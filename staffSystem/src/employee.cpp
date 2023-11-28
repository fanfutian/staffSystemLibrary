/**********************************************
 * Name：fanfutian
 * Time：2023/11/7
 * Filename：employee.cpp
 *********************************************/
#include "employee.h"


/*
 * 构造函数
 */
Employee::Employee(int id,string name,int dept_id){
    this->m_id = id;
    this->m_name = name;
    this->m_demptId = dept_id;
}


/*
 * 显示个人信息
 */
void Employee::showInfor(){
    cout << "职工编号：" << this->m_id << "\t职工姓名：" << this->m_name
        << "\t职称：" << this->getDeptment() << endl;
}


/*
 * 获取岗位信息
 */
string Employee::getDeptment(){
    return (string)"普通员工";
}