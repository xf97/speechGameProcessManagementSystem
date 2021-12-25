#ifndef SPEACKER_H
#define SPEACKER_H

//选手定义类
#include <iostream>
#include <string>

using namespace std;

class Player{
public:
    //构造方法
    Player(const string _name);
    Player();
    //get方法
    string getName() const;
    float getScore(int round) const;
    //set方法
    void setScore(int round, float score); 
    //重载打印函数
    friend ostream & operator<<(ostream & os, const Player & p);
private:
    string name;    //姓名
    float scores[2];    //两轮得分
};

#endif