#include <iostream>
#include <WorkManager.h>
#include <Work.h>
#include <Employee.h>
#include <Boss.h>

using namespace std;

WorkManager::WorkManager()
{

   fstream fst;
   fst.open(FILENAME, ios::in);
   if (!fst.is_open())
   {
      cout << "数据文件不存在" << endl;
      this->workArr = NULL;
      this->worknum = 0;
      this->isEmptyFile = true;
      fst.close();
      return;
   }
   char ch;
   fst >> ch;
   if (fst.eof())
   {
      cout << "数据文件为空" << endl;
      this->workArr = NULL;
      this->worknum = 0;
      this->isEmptyFile = true;
      fst.close();
      return;
   }
   fst.close();
   this->initWorkNum();
   //将数据加入东西
   this->initFileData();
};
//对象被销毁之前执行
WorkManager::~WorkManager()
{
   // 堆内存释放
   if (this->workArr != NULL)
   {
      delete[] this->workArr;
      this->workArr = NULL;
   }
};

void WorkManager::exitProcess()
{
   cout << "欢迎下次使用" << endl;
   system("pause");
   exit(0);
};

void WorkManager::menu()
{
   cout << "=====职工管理系统=====" << endl;
   cout << "=====0，退出       ==========" << endl;
   cout << "=====1，增加职工信息==========" << endl;
   cout << "=====2，显示职工信息==========" << endl;
};

void WorkManager::addWork()
{
   cout << "请输入批量操作新增人员的数量" << endl;
   int addworknum = 0;
   cin >> addworknum;
   if (addworknum > 0)
   {
      int newworknum = this->worknum + addworknum;
      Work **newspace = new Work *[newworknum];
      for (int i = 0; i < this->worknum; i++)
      {
         newspace[i] = this->workArr[i];
      }
      for (int i = 0; i < addworknum; i++)
      {
         cout << "请输入第" << this->worknum + 1 << "号员工的信息" << endl;
         int number;
         string name;
         int department_number;
         int type;
         Work *worknew = NULL;
         cout << "输入员工编号" << endl;
         cin >> number;
         cout << "输入员工姓名" << endl;
         cin >> name;
         cout << "输入部门编号" << endl;
         cin >> department_number;
         cout << "输入员工类型" << endl;
         cout << "1:普通员工" << endl;
         cout << "2:经理" << endl;
         cout << "3:老板" << endl;
         cin >> type;
         switch (type)
         {
         case 1:
            worknew = new Employee(number, name, department_number);
            break;
         case 2:
            worknew = new Employee(number, name, department_number);
            break;
         case 3:
            worknew = new Boss(number, name, department_number);
            break;
         default:
            cout << "输入错误" << endl;
            break;
         }

         newspace[this->worknum] = worknew;
      }

      delete[] this->workArr;
      this->workArr = newspace;
      this->worknum = newworknum;
      this->saveDataToFile();
      cout << "添加成功" << addworknum << "名新员工" << endl; 
      system("cls");
   }
   else
   {
      cout << "输入有误" << endl;
   }
}
void WorkManager::showAllWork()
{
   for(int i=0;i<this->worknum;i++){
      this->workArr[i]->showInfo();
   }
}
void WorkManager::saveDataToFile()
{
   ofstream fst;
   fst.open(FILENAME, ios::out);
   for (int i = 0; i < this->worknum; i++)
   {
      fst << this->workArr[i]->number << "  " << this->workArr[i]->name << "  " << this->workArr[i]->department_number << endl;
   }
   fst.close();
}

//初始化员工数量
void WorkManager::initWorkNum()
{
   fstream fst;
   fst.open(FILENAME, ios::in);
   int number;
   string name;
   int department_number;
   int num = 0;
   while (fst >> number && fst >> name && fst >> department_number)
   {
      num++;
   };
   this->worknum = num;
   fst.close();
}
void WorkManager::initFileData()
{
   fstream fst;
   fst.open(FILENAME, ios::in);
   int number;
   string name;
   int department_number;
   this->workArr = new Work *[this->worknum];
   int index = 0;
   while (fst >> number && fst >> name && fst >> department_number)
   {
      Work *newwork = NULL;
      if (department_number = 1)
      {
         newwork = new Employee(number, name, department_number);
      }
      if (department_number = 2)
      {
         // newwork = new Employee(number, name, department_number);
      }
        if (department_number = 3)
      {
         // newwork = new Boss(number, name, department_number);
      }
      this->workArr[index] = newwork;
      index++;
   };
   fst.close();
}