#include "Player.h"

//实现player类

//构造
Player::Player(){
    name = "";
    scores[0] = scores[1] = 0.0f;
}

Player::Player(const string _name): name(_name){
    scores[0] = 0.0f;
    scores[1] = 0.0f;   
}

//get方法
string Player::getName() const{
    return name;
}

//注意添加数组越界问题
float Player::getScore(int round) const{
    try
    {
        return scores[round - 1];
    }
    catch(const std::exception& e)
    {
        //要防止越界
        cerr<<"The given round is smaller than 0 or bigger than 1.\n";
        return 0.0f;
    }
}

//set方法
void Player::setScore(int round, float score){
    try
    {
        scores[round - 1] = score;
    }
    catch(const std::exception& e)
    {
        //要防止越界
        cout<<"The given round is smaller than 0 or bigger than 1.\n";
    }

}

//友元函数
ostream & operator<<(ostream & os, const Player & p){
    os<<p.getName()<<", round 1 score: "<<p.getScore(0)<<", round 2 score: "<<p.getScore(1)<<endl;
    return os;
}