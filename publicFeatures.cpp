#include "publicFeatures.hpp"

// //公共函数功能实现文件
// void cinNum(int & num, const string & tips){
//     cout<<tips;
//     while(true){
//         cin>>num;
//         //如果输入失败，比如类型不符
//         if(cin.fail()){
//             //则清空状态，重输
//             cin.clear();
//             cin.sync();
//             cout<<"Wrong type input, please re-enter your choice (must be number): ";
//             continue;
//         }
//         break;
//     }
// }