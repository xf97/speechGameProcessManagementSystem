#include "speechManager.h"

//speechManager实现文件
//构造函数
SpeechManager::SpeechManager(){

}

//析构函数
SpeechManager::~SpeechManager(){

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