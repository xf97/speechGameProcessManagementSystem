#ifndef SPEECHMANAGER_H
#define SPEECHMANAGER_H

//管理类
//包含以下功能
//提供菜单界面与用户交互
//对演讲比赛的流程进行控制
//与文件的读写交互

#include <iostream>
#include <string>

using namespace std;

//类名统一大写字母开头
class SpeechManager{
public:
    SpeechManager();    //构造
    ~SpeechManager();   //析构
    void showMenu();    //显示菜单功能
private:
    string id;  //选手id
    float score;    //选手分数
};

#endif