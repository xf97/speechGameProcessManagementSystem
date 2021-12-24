#include "speechManager.h"

//speechManager实现文件
//构造函数
SpeechManager::SpeechManager(){
    initSpeech();   //初始化
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

//析构函数
SpeechManager::~SpeechManager(){
    //无堆区数据，无需特殊处理
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