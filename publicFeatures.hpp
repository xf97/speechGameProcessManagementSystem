#ifndef PUBLICFEATURES_H
#define PUBLICFEATURES_H

//某些会用到的公共函数定义于此

#include <iostream>

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

#endif