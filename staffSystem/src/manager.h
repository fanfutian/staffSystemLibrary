/**********************************************
 * Name：fanfutian
 * Time：2023/11/7
 * Filename：manager.h
 *********************************************/
#pragma once

#include <iostream>
#include "work.h"


using namespace std;


class Manager:public Work{
public:
    // 构造函数
    Manager(int id,string name,int dept_id);

    // 显示个人信息
    virtual void showInfor();

    // 获取岗位信息
    virtual string getDeptment();
};