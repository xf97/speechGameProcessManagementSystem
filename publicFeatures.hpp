#ifndef PUBLICFEATURES_H
#define PUBLICFEATURES_H

//某些会用到的公共函数定义于此

#include <iostream>
#include <map>
#include <iterator>
#include "Player.h"

using namespace std;

//模板函数，好像此函数可以抽象为模板
template<typename inputType>
void cinNum(inputType & data, const string & tips){
    cout<<tips;
    while(true){
        cin>>data;
        //如果输入失败，比如类型不符
        if(cin.fail()){
            //则清空状态，重输
            cin.clear();
            cin.sync();
            cout<<"Wrong type input, please re-enter your input: ";
            continue;
        }
        break;
    }
}

//用于序列化数据
template<typename seqType>
void printSeq(const seqType & st){
    for(auto it = st.begin(); it != st.end(); ++ it){
        cout<<(*it)<<" ";
    }
    cout<<endl;
}

//用于输出各种类型的map
template<typename keyType, typename valueType>
void printMap(const map<keyType, valueType> & mp){
    for(auto it = mp.begin(); it != mp.end(); ++ it){
        cout<<it->first<<" "<<it->second;
    }
}

// //用于输出各种类型的multimap
// template<typename keyType, typename valueType>
// void printMultimap(const multimap<keyType, valueType> & mp){
//     for(auto it = mp.begin(); it != mp.end(); ++ it){
//         cout<<"id: "<<it->first<<" "<<it->second;
//     }
// }

//传入仿函数，用于比较Player的前后关系
class PlayerCompare{
public:
    bool operator()(const Player & p1, const Player & p2){
        if(p1.getScore(1) == p2.getScore(1) && p1.getScore(2) == p2.getScore(2)){
            //分数一样，比名字
            return p1.getName() < p2.getName();
        }
        else{
            if(p1.getScore(1) != p2.getScore(1)){
                return p1.getScore(1) < p2.getScore(1);
            }
            else{
                return p1.getScore(2) < p2.getScore(2);
            }
        }
    }
};



#endif