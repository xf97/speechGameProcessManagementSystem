#include "Player.h"

//实现player类

//构造
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
        return scores[round];
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
        scores[round] = score;
    }
    catch(const std::exception& e)
    {
        //要防止越界
        cout<<"The given round is smaller than 0 or bigger than 1.\n";
    }

}