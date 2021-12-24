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

//抽签，开始演讲比赛，显示结果
//抽签，开始眼睛比赛，显示前三名结果，保存分数
//类名统一大写字母开头
class SpeechManager{
public:
    SpeechManager();    //构造
    ~SpeechManager();   //析构
    void showMenu();    //显示菜单功能
};

#endif