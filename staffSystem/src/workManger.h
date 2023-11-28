/**********************************************
 * Name：fanfutian
 * Time：2023/11/5
 * Filename：workManger.h
 *********************************************/
 // 防止头文件重复包含
#pragma once

#include <iostream>
#include "work.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#include <fstream>

using namespace std;

/*
 * 定义职工管理类
 *      成员函数采用类内声明，类外实现
 */
class WorkManger{
public:

    // 记录职工人数
    int m_staffNumber;

    // 使用数组指针记录职工地址（数组指针--指向数组的指针）
    Work** m_staffArray;

    // 判断文件是否为空
    bool m_file_isEmpty;

    // 构造函数的声明
    WorkManger();

    // 展示菜单
    void ShowMenu();

    // 退出系统
    void ExitSystem();

    // 添加职工信息
    void AddStaff();

    // 删除职工信息
    void PopStaffInfo();

    // 修改职工信息
    void ModifyStaffInfo();

    // 析构函数
    ~WorkManger();

    // 查找职工信息
    void FindStaffInfo();

    // 显示所有职工信息
    void ShowAllInfo();

    // 写入文件
    void SaveStaffInfo();

    // 清空数据
    void EmployFileInfo();

private:
    // 统计文件中人数
    int GetFileNum();

    // 使用文件中的数据进行初始化
    void InitStaff();

    // 通过姓名查找职工
    int GetStaffName(string name);

    // 通过ID查找职工
    int GetStaffId(int id);
};