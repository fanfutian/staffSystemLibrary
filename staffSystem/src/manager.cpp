/**********************************************
 * Name：fanfutian
 * Time：2023/11/7
 * Filename：manager.cpp
 *********************************************/
#include "manager.h"

/*
 * 构造函数
 */
Manager::Manager(int id, std::string name, int dept_id) {
    this->m_id = id;
    this->m_name = name;
    this->m_demptId = dept_id;
}



/*
 * 显示个人信息
 */
void Manager::showInfor(){
    cout << "职工编号：" << this->m_id << "\t职工姓名：" << this->m_name
         << "\t职称：" << this->getDeptment() << endl;
}



/*
 * 获取岗位信息
 */
string Manager::getDeptment(){
    return (string)"经理";
}