/**********************************************
 * Name：fanfutian
 * Time：2023/11/5
 * Filename：work.h
 *********************************************/
#pragma once

#include <iostream>
#include <string>
using namespace std;


/*
 * 创建职工抽象类
 */
class Work{
public:
    // 职工编号
    int m_id;

    // 职工姓名
    string m_name;

    // 职工部门
    int m_demptId;

    // 显示个人信息
    virtual void showInfor() = 0;

    // 获取岗位信息
    virtual string getDeptment() = 0;
};