#include<iostream>
#include<string>
#include<Boss.h>
using namespace std;
Boss::Boss(int number ,string name,int departnumber){
  this->name =name;//员工姓名
  this->number=number;// 职工编号
  this->department_number = departnumber;//部门编号
}; 
void Boss::showInfo(){
   cout<<"职工："<<name<< "部门编号是:"<< department_number<< "员工编号是："<< number<<"职位是老板 ,他的职责是管理整个公司" <<endl;
}
