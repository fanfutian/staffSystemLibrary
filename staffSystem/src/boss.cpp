/**********************************************
 * Name：fanfutian
 * Time：2023/11/7
 * Filename：boss.cpp
 *********************************************/
#include "boss.h"

using namespace std;


/*
 * 构造函数
 */
Boss::Boss(int id,string name,int dept_id) {
    this->m_id = id;
    this->m_name = name;
    this->m_demptId = dept_id;
}


/*
 * 显示个人信息
 */
void Boss::showInfor(){
    cout << "职工编号：" << this->m_id << "\t职工姓名：" << this->m_name
         << "\t职称：" << this->getDeptment() << endl;
}


/*
 * 获取岗位信息
 */
string Boss::getDeptment(){
    return (string)"老板";
}