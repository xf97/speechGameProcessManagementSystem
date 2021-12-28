#include "speechManager.h"

//speechManager实现文件
//构造函数
SpeechManager::SpeechManager(){
    initSpeech();   //初始化
    creatPlayers(); //初始化选手
    srand((unsigned int)time(NULL));    //为后续随机操作初始化随机种子
    loadData();
}

//初始化演讲比赛
void SpeechManager::initSpeech(){
    players.clear();    //清空
    round1Winners.clear();  
    top3Winners.clear();
    idForPlayer.clear();
    //置轮数
    roundIndex = 1;
    //过往记录清空
    pastData.clear();
}

//调试代码
const vector<int> & SpeechManager::getPlayers() const{
    return players;
}

const map<int, Player> & SpeechManager::getInfoMap() const{
    return idForPlayer;
}

//析构函数
SpeechManager::~SpeechManager(){
    //无堆区数据，无需特殊处理
}

void SpeechManager::creatPlayers(){
    //就是命名就好了
    char nameSeed = 'A';
    int idSeed = 10001;
    for(int i = 0; i < PLAYERS_NUM; ++ i){
        string name = "Player ";
        //要分开写才能是char形式上去
        name += static_cast<char>(nameSeed + i);
        int id = idSeed + i;
        Player p(name);
        //压入数组
        players.push_back(id);
        //压入对应关系
        idForPlayer.insert(make_pair(id, p));
    }
}

//显示菜单功能
void SpeechManager::showMenu(){
    cout<<"*********************************\n";
    cout<<"Welcome to Xiaofeng's Speech Game\n";
    cout<<"1. Start the speech game.\n";
    cout<<"2. Check the past game's winners.\n";
    cout<<"3. Clear all past game's data.\n";
    cout<<"0. Quit this program.\n";
    cout<<"*********************************\n";
}

void SpeechManager::speechDraw(vector<int> & _players, int _round){
    cout<<"The #"<<_round<<" round'players are drawing...\n";
    cout<<"-----------------------\n";
    cout<<"The drawing result is shown below:\n";
    random_shuffle(_players.begin(), _players.end());
    printSeq(_players);
}


void SpeechManager::speechContest(const vector<int> & _players, int _round){
    cout<<"*** The #"<<_round<<" round game starts ***\n";
    //要记住每组六个人，取前三个
    int num = 0;    //已经比赛的人数，用于分组
    //因为要把得分前几位的选手调出来，所以要建立score和id的对应关系，故用multimap，分数可能相同
    multimap<float, int, greater<float>> _1GroupScores;
    //遍历所有参赛选手进行打分
    for(auto it = _players.begin(); it != _players.end(); ++ it){
        //评委打分
        //使用双端队列是为了去掉最高分和最低分方便
        deque<float> givenScore;
        //十个评委随机打分
        for(int i = 0; i < 10; ++ i){
            float score = (rand() % 401 + 600) / 10.0f; //生成60.0-100.0的随机小数
            givenScore.push_back(score);
        }
        //排序，去掉最高和最低
        sort(givenScore.begin(), givenScore.end(), greater<float>());   //重载一下，从高向低排
        givenScore.pop_back();
        givenScore.pop_front();
        //计算平均分
        float averageScore = accumulate(givenScore.begin(), givenScore.end(), 0) / float(givenScore.size());
        //记录分数
        idForPlayer[(*it)].setScore(_round, averageScore);
        ++ num;
        //记录分数
        _1GroupScores.insert(make_pair(averageScore, (*it)));
        //判断是否一组人比赛完了
        if(num % ONE_GROUP_SIZE == 0){
            //如果是的话，列出一组的排名，然后取前三个
            int count = 0;  //取出前三名的设置
            cout<<"The #"<<(num / ONE_GROUP_SIZE)<<" group's game result: \n";
            for(auto mIt = _1GroupScores.begin(); mIt != _1GroupScores.end(); ++ mIt, ++ count){
                cout<<"id: "<<mIt->second<<", name: "<<idForPlayer[mIt->second].getName()<<
                    ", score: "<<mIt->first<<endl;
                if(count < 3){
                    if(_round == 1){
                        round1Winners.push_back(mIt->second);
                    }
                    else{
                        //最终胜利者
                        top3Winners.push_back(mIt->second);
                    }
                }
            }
            _1GroupScores.clear();  //每组弄好之后清空
        }
    }
    cout<<"*** The #"<<_round<<" round game ends ***\n";
}

void SpeechManager::startSpeech(){
    //第一轮比赛
    //抽签
    speechDraw(players, roundIndex);
    system("pause");
    //比赛
    speechContest(players, roundIndex);
    system("pause");
    //显示晋级结果
    showScore(roundIndex);
    //轮次++
    ++ roundIndex; 
    //第二轮比赛
    //抽签
    speechDraw(round1Winners, roundIndex);
    system("pause");
    //比赛
    speechContest(round1Winners, roundIndex);
    system("pause");
    //显示最终结果
    showScore(roundIndex);
    //保存分数
    saveData();
    cout<<"This speech game is finished.\n";
    //要重置比赛，实现记录的实时更新
    initSpeech();
    creatPlayers(); 
    loadData();
    //roundIndex = 1;
    return;
}

void SpeechManager::showScore(int _round){
    //vector<int> tempV;
    cout<<"The #"<<_round<<" game's winners result is shown below:\n";
    if(_round == 1){
        for(auto it = round1Winners.begin(); it != round1Winners.end(); ++ it){
            cout<<"id: "<<(*it)<<", name: "<<idForPlayer[(*it)].getName()<<", score: "<<
                idForPlayer[(*it)].getScore(_round)<<endl;
        }
    }
    else{
        for(auto it = top3Winners.begin(); it != top3Winners.end(); ++ it){
            cout<<"id: "<<(*it)<<", name: "<<idForPlayer[(*it)].getName()<<", score: "<<
                idForPlayer[(*it)].getScore(_round)<<endl;
        }
    }
    //假装打印个菜单
    //showMenu();
}

void SpeechManager::saveData(){
    ofstream ofs(DATA_PATH, ios::out | ios::app);   //追加写入，不清空之前的数据
    if(!ofs.is_open()){
        cerr<<"Data file open failed, please check!\n";
        ofs.close();
        return;
    }
    //将id和分数搞进去
    //csv的数据使用逗号分割
    for(auto it = top3Winners.begin(); it != top3Winners.end(); ++ it){
        //id 姓名 得分
        //追加的时候这一届会跟上一届的掺和在一起
        ofs<<(*it)<<","<<idForPlayer[(*it)].getName()<<","<<idForPlayer[(*it)].getScore(2)<<",";
    }
    ofs<<"\n";
    ofs.close();
    cout<<"Data has saved!.\n";
    return;
}

void SpeechManager::loadData(){
    ifstream ifs(DATA_PATH, ios::in);

    if(!ifs.is_open()){
        cerr<<"Past data file doesn't exist.\n";
        ifs.close();
        return;
    }
    else{
        //要看是否是空文件，因为会有清空操作
        char ch;
        ifs>>ch;    //读一个进来试一下
        if(ifs.eof()){
            cerr<<"Data file is empty, no past data is recorded!\n";
            ifs.close();
            return;
        }
        else{
            //ifs.seekg(0, ios::beg); //返回首位置
            ifs.putback(ch);  //把读入的字符放回去
            //文件不为空
            string aLine = "";
            int index = 1;  //届数
            while(getline(ifs, aLine)){
                //每次读一届的
                //要分隔逗号，利用find和substr
                //cout<<aLine<<endl;
                int start = 0;  //开始检索位置
                int pos = -1;   //逗号位置
                vector<string> aLineContent;    //一行初始化一次
                do{
                    pos = aLine.find(',', start);
                    aLineContent.emplace_back(aLine.substr(start, pos - start));
                    start = pos + 1;    //更新搜索起始位置
                }while(start < aLine.size() - 1 && pos >= 0 && pos < aLine.size());
                //在有逗号且没有超限的时候循环
                // for(string i : aLineContent){
                //     cout<<i<<" &&& ";
                // }
                // cout<<endl;
                pastData.insert(make_pair(index, aLineContent));
                ++ index;
            }
            ifs.close();
            return;
        }
    }
}

//查看过往记录
void SpeechManager::checkPastData() const{
    if(pastData.empty()){
        cout<<"The past data file is empty, no records can output.\n";
        return;
    }
    for(auto it = pastData.begin(); it != pastData.end(); ++ it){
        cout<<"The #"<<it->first<<" speech game, 1st id: "<<it->second[0]<<", name: "<<it->second[1]<<", score: "<<it->second[2]<<",\n"
            <<"2nd id: "<<it->second[3]<<", name: "<<it->second[4]<<", score: "<<it->second[5]<<",\n"
            <<"3rd id: "<<it->second[6]<<", name: "<<it->second[7]<<", score: "<<it->second[8]<<".\n";
    }
}

void SpeechManager::clearData(){
    //清空数据需要再次确认
    int reType = 2; //再次确认操作
    do{
        cinNum(reType, "Be sure to clean all data (1-yes, 2-no): ");
    } while(reType != 1 && reType != 2);
    if(reType == 1){
        ofstream ofs(DATA_PATH, ios::trunc);    //使用trunc清空数据
        ofs.close();
        //重置值，更新记录
        initSpeech();
        creatPlayers();
        loadData(); 
        cout<<"Clean all data -- Done!\n";
        return;
    }
    else{
        return;
    }
}