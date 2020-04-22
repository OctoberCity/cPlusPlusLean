#pragma once
#include <iostream>
#include <string>
using namespace std;
// 职工抽象类
// 普通员工
// 经理类
// 老板类
// 主要使用类的抽象，多态
class Work
{

public:
    virtual void showInfo() = 0; 
    int number;  // 员工编号
    string name; //名字
    int department_number; // 部门类型
};
