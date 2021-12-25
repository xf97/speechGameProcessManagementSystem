#include "headFiles.h"

/*
需求
12个人，比赛共两轮，第一轮淘汰赛，第二轮决赛
每名选手都有编号，10001-10012
分组比赛，每组6人
第一轮两个小组，按照选手编号抽签后顺序演讲
十个评委分别给每名选手打分， 去掉最高的和最低的，求出平均分作为选手的成绩
第一轮淘汰本组最后三个选手
第二轮为决赛，六人参加，前三名有奖项
每轮比赛后需要显示晋级选手的信息
*/

/*
功能：
开始演讲比赛，每个阶段都要给用户一个提示，用户按下任意键后进入下一个阶段
查看往届记录，查看之前比赛的前三名结果，数据用csv文件保存
清空比赛记录
退出比赛程序
*/

int main(){
    int choice = -1;    //用户选择
    SpeechManager sm;
    //printMap(sm.getInfoMap());
    while(choice != 0){
        sm.showMenu();
        cinNum(choice, "Please enter your choice: ");
        switch (choice)
        {
        case 0:
            //退出系统
            //注意，可能涉及写入数据
            break;
        case 1:
            //开始比赛
            sm.startSpeech();
            break;
        case 2:
            //查看过往记录
            break;
        case 3:
            //清空记录
            break;
        default:
            cout<<"you have entered the wrong number, please enter again.\n";
            break;
        }
        system("pause");
        system("cls");
    }
    cout<<"Already quit this system.\n";
    return 0;
}