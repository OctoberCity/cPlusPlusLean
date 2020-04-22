// 线性表
// 有序
#include <iostream>
using namespace std;
struct student
{
  char name[10];
  int math;
  int english;
};
void fun1()
{
  int arr[10] = {0, 23, 4, 0, 56, 6, 7, 8, 0, 90};
  int *sr = arr;
  cout << "数组值" << sr << endl;
};
// 结构数组
void fun2()
{
  struct student std[3] = {{"hjw",12,12},{"hjw2",24,56},{"hjw3",34,55}};
  for (int i =0;i<3;i++)
  {
    cout<<"姓名："<<std[i].name<<"数学成绩"<<'\t'<<std[i].math<<"英语成绩"<<'\t'<<std[i].english<<endl;
  }
}
// 字符串，字符数组，以“\0”代表数组的结束
/***常见方式***/


int main()
{
  fun1();
  fun2();
  return 0;
}