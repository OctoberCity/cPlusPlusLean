#include<iostream>
#include<string>
#include<Employee.h>
using namespace std;
Employee::Employee(int number ,string name,int departnumber){
  this->name =name;//员工姓名
  this->number=number;// 职工编号
  this->department_number = departnumber;//部门编号
};  
void Employee::showInfo(){
   cout<<"职工："<<name<< "部门编号是:"<< department_number<< "员工编号是："<< number<<"职位是普通员工 ,他的职责是车间工作" <<endl;
}
