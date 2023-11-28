/**********************************************
 * Name：fanfutian
 * Time：2023/11/5
 * Filename：workManger.cpp
 *********************************************/
 // 导入自定义的头文件
#include "workManger.h"


/*
 * 类外实现构造函数
 */
WorkManger::WorkManger() {
    ifstream  ifs;
    // 1、文件不存在时：
    ifs.open("StaffInfor.txt",ios::in);
    if(!ifs.is_open()){
        cout << "文件不存在！" << endl;
        // 初始化管理者的属性值
        this->m_staffNumber = 0;
        this->m_staffArray = nullptr;
        this->m_file_isEmpty = true;
        ifs.close();
        return;
    }

    // 2、文件存在，内容为空
    char ch;
    ifs >> ch;
    if(ifs.eof()){
        cout << "文件为空！" << endl;
        // 初始化管理者的属性值
        this->m_staffNumber = 0;
        this->m_staffArray = nullptr;
        this->m_file_isEmpty = true;
        ifs.close();
        return;
    }

    // 3、文件存在，且有数据
    int num = this->GetFileNum();
    cout << "文件存在！人数为：" << num << endl;
    // 将记录人数的数据进行更新--（初始化）
    this->m_staffNumber = num;
    // 根据读到的人数创建数组空间的大小
    this->m_staffArray = new Work* [this->m_staffNumber];
    // 空间开辟成功后进行数据初始化
    this->InitStaff();
}


/*
 * 统计文件中人数---文件存在且有数据
 *  统计人数的同时进行文件中数据的初始化---(不行，需要知道人数先创建空间才可以进行初始化数据）
 */
int WorkManger::GetFileNum(){
    // 创建文件流对象
    ifstream ifs;
    // 打开文件 -- 读文件的方式
    ifs.open("StaffInfor.txt",ios::in);
    // 定义变量记录读入的数据
    int id;
    string name,get_deptment;
    // 循环读入数据--将每一行的数据读入变量中
    int numStaff = 0;
    while(ifs >> id && ifs >> name && ifs >> get_deptment){
//        // 创建职工父类
//        Work* worker = nullptr;
//        // 根据不同的部门创建不同的对象
//        if(get_deptment == "普通员工"){
//            worker = new Employee(id,name,1);
//        }else if(get_deptment == "经理"){
//            worker = new Manager(id,name,2);
//        }else{
//            worker = new Boss(id,name,3);
//        }
//        // 存放到数组中
//        this->m_staffArray[numStaff] = worker;
//        // 每次读完一行表示有一个人
        numStaff++;
    }
//    // 关闭文件流
//    ifs.close();
    // 返回统计的人数
    return numStaff;
}


/*
 * 使用文件中的数据进行初始化
 */
void WorkManger::InitStaff(){
    // 创建文件流对象
    ifstream ifs;
    // 打开文件 -- 读文件的方式
    ifs.open("StaffInfor.txt",ios::in);
    // 定义变量记录读入的数据
    int id;
    string name,get_deptment;
    // 循环读入数据--将每一行的数据读入变量中
    int numStaff = 0;
    while(ifs >> id && ifs >> name && ifs >> get_deptment){
        // 创建职工父类
        Work* worker = nullptr;
        // 根据不同的部门创建不同的对象
        if(get_deptment == "普通员工"){
            worker = new Employee(id,name,1);
        }else if(get_deptment == "经理"){
            worker = new Manager(id,name,2);
        }else{
            worker = new Boss(id,name,3);
        }
        // 存放到数组中
        this->m_staffArray[numStaff] = worker;
        // 每次读完一行表示有一个人
        numStaff++;
    }
    // 关闭文件流
    ifs.close();
}



/*
 * 类外实现析构函数
 */
WorkManger::~WorkManger() {
    // 程序结束之后需要将堆区创建的空间释放掉
    if(this->m_staffArray != nullptr){
        // 先将数组中存放的地址位置的空间是否，在释放数组
        for(int i = 0; i < this->m_staffNumber; i++){
            // 将创建的指针数组中的对应指针位置开启的空间释放
            if(this->m_staffArray[i] != nullptr){
                delete this->m_staffArray[i];
            }
        }
        // 再将指针数组释放
        delete[] this->m_staffArray;
        this->m_staffArray = nullptr;
    }
}


/*
 * 展示菜单
 */
void WorkManger::ShowMenu() {
    cout << "**********************************************" << endl;
    cout << "************** 欢迎使用职工管理系统 *************" << endl;
    cout << "*************0、退出系统  1、添加信息************" << endl;
    cout << "*************2、显示信息  3、删除信息************" << endl;
    cout << "*************4、修改信息  5、查找信息************" << endl;
    cout << "*************6、编号排序  7、清空文档************" << endl;
    cout << "**********************************************" << endl;
}


/*
 * 添加职工信息
 */
void WorkManger::AddStaff(){
    cout << "请输入添加的职工数量：";
    int num = 0;
    cin >> num;
    // num大于0表示添加，小于0表示输入有误
    if(num > 0){
        // 计算需要开辟的空间大小（新空间 = 原来大小 + 准备添加的人数）
        int newSize = this->m_staffNumber + num;

        // 开辟空间
        Work** newArry = new Work *[newSize];

        // 将原来的数据拷贝到新开辟的空间中
        if(this->m_staffArray != nullptr){
            for(int i = 0; i < this->m_staffNumber; i++){
                // 将原来数组对应下标的元素拷贝到新数组对应的位置
                newArry[i] = this->m_staffArray[i];
            }
        }

        // 批量添加职工信息
        for(int i = 0; i < num; i++){
            // 定义添加的元素
            int id,dept_id;
            string name;

            cout << "请输入第" << i+1 << "个新职工的编号：";
            cin >> id;
            cout << "请输入第" << i+1 << "个新职工的姓名：";
            cin >> name;
            M:cout << "岗位有：1、普通员工\t2、经理\t3、老板" << endl;
            cout << "请选择职工岗位：";
            cin >> dept_id;

            // 根据不通的岗位创建不同的对象
            Work* worker = nullptr;
            switch (dept_id) {
                case 1:
                    worker = new Employee(id,name,dept_id);
                    break;
                case 2:
                    worker = new Manager(id,name,dept_id);
                    break;
                case 3:
                    worker = new Boss(id,name,dept_id);
                    break;
                default:
                    if(dept_id<=0 || dept_id >=4){
                        cout << "输入错误！";
                        goto M;
                    }
                    break;
            }

            // 将床=创建的新职工保存到数组中--保存的位置是原来数组的人数加上第i个元素
            newArry[this->m_staffNumber + i] = worker;
        }

        // 释放原有空间
        delete[] this->m_staffArray;

        // 更新新空间的指向
        this->m_staffArray = newArry;

        // 更新职工人数
        this->m_staffNumber = newSize;

        // 提示添加成功
        cout << "成功添加"  << num << "个新职工！！"  << endl;

        // 写入文件
        WorkManger::SaveStaffInfo();

        // 将判断文件为空的标志制为false
        this->m_file_isEmpty = false;

    }else{
        cout << "输入有误！人数需大于0！！" << endl;
    }
}


/*
 * 显示所有职工信息
 */
void WorkManger::ShowAllInfo(){
    // 判断文件是否为空和存在
    if(this->m_file_isEmpty){
        cout << "文件不存在或为空！";
    }else{
        for (int i = 0; i < this->m_staffNumber; ++i) {
            // 利用多态调用showInfor()函数
            this->m_staffArray[i]->showInfor();
        }
    }
}


/*
 * 数据写入文件
 */
void WorkManger::SaveStaffInfo(){
    // 创建流对象
    ofstream ofs;
    // 打开文件---已写入的方式打开文件
    ofs.open("StaffInfor.txt",ios::out);
    // 循环将数据写入文件
    for(int i = 0; i < this->m_staffNumber; i++){
        ofs << this->m_staffArray[i]->m_id << " "
            << this->m_staffArray[i]->m_name << " "
            << this->m_staffArray[i]->getDeptment() << endl;
    }
    // 关闭流对象
    ofs.close();
}


/*
 * 删除职工信息
 */
void WorkManger::PopStaffInfo(){
    // 判断文件是否为空或存在
    if(this->m_file_isEmpty){
        cout << "文件不存在或为空！" << endl;
    }else{
        int pop_id;
        cout << "情输入你要删除的职工的职工编号：";
        cin >> pop_id;
        // 通过id查找信息
        int index = this->GetStaffId(pop_id);
        if(index != -1){
            cout << "删除的职工信息如下：" << endl;
            this->m_staffArray[index]->showInfor();
            // 数组中数据的删除是数据元素的前移(index位置开始后面的元素向前移动）
            for(int i = index; i < this->m_staffNumber - 1; i++){
                this->m_staffArray[i] = this->m_staffArray[i+1];
            }
            // 人数减1
            this->m_staffNumber--;
            // 更新文件信息
            this->SaveStaffInfo();
            cout << "删除成功！" << endl;
        }else{
            cout << "没有该职工信息！" << endl;
        }
    }
}


/*
 * 修改职工信息
 */
void WorkManger::ModifyStaffInfo(){
    // 判断文件是否为空或存在
    if(this->m_file_isEmpty){
        cout << "文件不存在或为空！"  << endl;
    }else{
        int moddify_id;
        cout << "请输入要修改的职工的职工编号：";
        int index = this->GetStaffId(moddify_id);
        if(index != -1){
            cout << "需要修改的职工信息如下：" << endl;
            this->m_staffArray[index]->showInfor();
            // 释放对应数组下标记录的地址
            delete this->m_staffArray[index];
            // 定义变量重新开辟空间记录数据
            int new_id = 0,new_dept_id = 0;
            string new_name;
            cout << "请输入新的职工编号：";
            cin >> new_id;
            cout << "请输入新的职工姓名：";
            cin >> new_name;
            N:cout << "岗位有：1、普通员工\t2、经理\t3、老板" << endl;
            cout << "请选择职工岗位：";
            cin >> new_dept_id;

            // 创建父类对象
            Work* worker = nullptr;
            // 根据岗位创建子类对象，开辟空间
            switch (new_dept_id) {
                case 1:
                    worker = new Employee(new_id,new_name,new_dept_id);
                    break;
                case 2:
                    worker = new Manager(new_id,new_name,new_dept_id);
                    break;
                case 3:
                    worker = new Boss(new_id,new_name,new_dept_id);
                    break;
                default:
                    cout << "选择错误！"<< endl;
                    goto N;
            }
            // 将新开辟的空间地址添加到数组中
            this->m_staffArray[index] = worker;
            cout << "修改成功！" << endl;
            // 更新文件信息
            this->SaveStaffInfo();
        }else{
            cout << "没有该职工信息！" << endl;
        }
    }
}


/*
 * 查找职工信息
 */
void WorkManger::FindStaffInfo(){
    // 判断文件是否为空或者不存在
    if(this->m_file_isEmpty){
        cout << "文件为空或者不存在" << endl;
    }else{
        int chose;
        cout << "1、按照姓名查找 2、按照编号查找" << endl;
        cout << "请选择：";
        cin >> chose;
        if(chose == 2){
            int find_id;
            cout << "请输入需要查找的职工编号：";
            cin >> find_id;
            int index = this->GetStaffId(find_id);
            if(index != -1){
                cout << "找到对应信息：" << endl;
                this->m_staffArray[index]->showInfor();
            }else{
                cout << "通过编号为 " << find_id << "没有找到对应职工信息" << endl;
            }
        }else if(chose == 1){
            string find_name;
            cout << "请输入需要查找的职工编号：";
            cin >> find_name;
            int index = this->GetStaffName(find_name);
            if(index != -1){
                cout << "找到对应信息：" << endl;
                this->m_staffArray[index]->showInfor();
            }else{
                cout << "通过编号为 " << find_name << "没有找到对应职工信息" << endl;
            }
        }else{
            cout << "输入错误！" << endl;
        }
    }
}


/*
 * 退出系统
 */
void WorkManger::ExitSystem() {
    cout << "欢迎下次使用!!" << endl;
    exit(0);
}



/*
 * 通过姓名查找职工
 */
int WorkManger::GetStaffName(string name){
    // 遍历数组
    for(int i = 0; i < this->m_staffNumber; i++){
        // 判断是否是要查找的职工
        if(this->m_staffArray[i]->m_name == name){
            return i;
        }
    }
    // 循环结束表示没有找到
    return -1;
}


/*
 * 通过ID查找职工
 */
int WorkManger::GetStaffId(int id){
    // 遍历数组
    for(int i = 0; i < this->m_staffNumber; i++){
        // 判断是否是要查找的职工
        if(this->m_staffArray[i]->m_id == id){
            return i;
        }
    }
    // 循环结束表示没有找到
    return -1;
}


// 清空数据
void WorkManger::EmployFileInfo(){
    int clease;
    cout << "1、确定清空 2、返回" << endl;
    cout << "确定清空数据:";
    cin >> clease;
    if(clease == 1){
        // 删除文件后重新创建---改变打开文件的方式
        ofstream ofs("StaffInfor.txt",ios::trunc);
        ofs.close();
        if(this->m_staffArray != nullptr){
            // 先将数组中存放的地址位置的空间是否，在释放数组
            for(int i = 0; i < this->m_staffNumber; i++){
                // 删除堆区的每一个数据
                if(this->m_staffArray[i] != nullptr){
                    delete this->m_staffArray[i];
                }
            }
            // 删除堆区的数组指针
            delete[] this->m_staffArray;
            this->m_staffArray = nullptr;
        }
        cout << "数据全部清空完成！" << endl;
    }else if(clease == 2){
        return;
    }else{
        cout << "输入错误！" << endl;
    }
}