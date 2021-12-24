#include "speechManager.h"

//speechManager实现文件
//构造函数
SpeechManager::SpeechManager(){
    initSpeech();   //初始化
    creatPlayers(); //初始化选手
}

//初始化演讲比赛
void SpeechManager::initSpeech(){
    players.clear();    //清空
    round1Winners.clear();  
    top3Winners.clear();
    idForPlayer.clear();
    //置轮数
    roundIndex = 1;
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
    cout<<"2. Get the past game's winners.\n";
    cout<<"3. Clear all past game's data.\n";
    cout<<"4. Quit this program.\n";
    cout<<"*********************************\n";
}