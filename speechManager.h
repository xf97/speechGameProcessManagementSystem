#ifndef SPEECHMANAGER_H
#define SPEECHMANAGER_H

//管理类
//包含以下功能
//提供菜单界面与用户交互
//对演讲比赛的流程进行控制
//与文件的读写交互

#include <iostream>
#include <string>
#include <vector>
#include "Player.h"
#include <map>

using namespace std;

const int PLAYERS_NUM = 12; //参赛选手数量

//抽签，开始演讲比赛，显示结果
//抽签，开始眼睛比赛，显示前三名结果，保存分数
//类名统一大写字母开头
class SpeechManager{
public:
    SpeechManager();    //构造
    ~SpeechManager();   //析构
    void showMenu();    //显示菜单功能
    void initSpeech();  //初始化演讲比赛
    void creatPlayers();    //初始化创建PLAYERS_NUM名选手
    const vector<int> & getPlayers() const;
    const map<int, Player> & getInfoMap() const; 
private:
    vector<int> players; //所有参赛选手的id，下同
    vector<int> round1Winners;   //第一轮晋级选手
    vector<int> top3Winners; //最终的前三名
    map<int, Player> idForPlayer;   //记录id与player对应关系的映射
    int roundIndex; //比赛轮次
};

#endif