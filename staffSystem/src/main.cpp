/**********************************************
 * Name：fanfutian
 * Time：2023/11/5
 * filename：main.cpp
 *********************************************/
#include <iostream>
#include "workManger.h"

using namespace std;

int main() {

    // 创建管理者对象
    WorkManger wk;
    // 定义变量
    int choice = 0;
    while (true){
        // 调用菜单
        wk.ShowMenu();
        cout << "输入你的选择：";
        cin >> choice;

        switch (choice) {
            case 0:                         // 退出系统
            wk.ExitSystem();
                break;
            case 1:                         // 添加信息
            wk.AddStaff();
                break;
            case 2:                         // 显示信息
            wk.ShowAllInfo();
                break;
            case 3:                         // 删除信息
            wk.PopStaffInfo();
                break;
            case 4:                         // 修改信息
            wk.ModifyStaffInfo();
                break;
            case 5:                         // 查找信息
            wk.FindStaffInfo();
                break;
            case 6:                         // 排序

                break;
            case 7:                         // 清空文档
            wk.EmployFileInfo();
                break;
            default:
                system("cls");
                cout << "输入错误！" << endl;
        }
    }
    return 0;
}