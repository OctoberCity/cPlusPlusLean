#include <iostream>
#include <string>
using namespace std;
#include <workManager.h>

int main()
{
    WorkManager wm;
    Work *work = NULL;
    int choice = 0;

    while (true)
    {
        wm.menu();
        cout << "请输入数字作为你的选择：" << endl;
        cin >> choice;
        switch (choice)
        {
        case 0: // 推出程序
            wm.exitProcess();
            break;
        case 1: // 新增员工
            wm.addWork();
            break;
        case 2: // 查询所有员工
            wm.showAllWork();
            break;
        default:
            system("cls");
            break;
        }
    }

    system("pause");
    return 0;
}