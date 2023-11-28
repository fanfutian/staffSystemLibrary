/**********************************************
 * Name：fanfutian
 * Time：2023/11/7
 * filename：employee.h
 *********************************************/
#pragma once

#include <iostream>
#include "work.h"

using namespace std;


/*
 * 创建普通员工类---继承Work类
 */
class Employee:public Work{
    // 重写work类中的纯虚函数---内部声明类外实现
public:
    // 构造函数
    Employee(int id,string name,int dept_id);

    // 显示个人信息
    virtual void showInfor();

    // 获取岗位信息
    virtual string getDeptment();
};