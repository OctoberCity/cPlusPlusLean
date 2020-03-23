#include <iostream>
#include <string>
// #include <ctime>
using namespace std;
#define MAX 1000

// 联系人结构体
struct People
{
    string name;
    int age;
    int sex; //0女 男
    string add;
    string phone;
};
// 通讯录结构体
struct AddressBooks
{
    struct People addressp[MAX];
    int peoplenum;
};

void addpeople(AddressBooks *abs)
{
    if (abs->peoplenum >= MAX)
    {
        return;
    }
    string name;
    string phone;
    int age;
    int sex;
    string add;
    cout << "请输入联系人名字" << endl;
    cin >> name;
    abs->addressp[abs->peoplenum].name = name;
    cout << "请输入联系人年龄"<<endl;
    cin >> age;
    abs->addressp[abs->peoplenum].age = age;
    cout << "请输入联系人性别（0,女，1男）" << endl;
    cin >> sex;
    abs->addressp[abs->peoplenum].sex = sex;
    cout << "请输入联系人联系地址" << endl;
    cin >> add;
    abs->addressp[abs->peoplenum].add = add;
    cout << "请输入联系人联系电话" << endl;
    cin >> phone;
    abs->addressp[abs->peoplenum].phone = phone; 
    abs->peoplenum++;
    cout << "添加成功" << endl;
};

void dispalypeople(AddressBooks *abs)
{
    cout << "\t姓名\t性别\t年龄\t家庭住址\t电话号码" << endl;
    for (int i = 0; i < abs->peoplenum; i++)
    {
        string sex = abs->addressp[i].sex == 0 ? "女" : "男";
        cout << "\t" << abs->addressp[i].name << "\t" << sex << "\t" <<abs->addressp[i].age<< "\t" <<abs->addressp[i].add<< "\t" <<abs->addressp[i].phone<< endl;
    };
}

void printmenu()
{
    cout << "============================" << endl;
    cout << "=======1 /t 添加联系人=======" << endl;
    cout << "=======2 /t 显示联系人=======" << endl;
    cout << "=======3 /t 查找联系人=======" << endl;
    cout << "=======4 /t 修改联系人=======" << endl;
    cout << "=======5 /t 清空联系人=======" << endl;
    cout << "=======6 /t 退出联系人=======" << endl;
};
int main()
{
    int order;
    AddressBooks abs;
    abs.peoplenum = 0;
    printmenu();
    while (true)
    {
        cout << "请输入你的操作" << endl;
        cin >> order;
        switch (order)
        {
        case 0:
            cout << "欢迎下次使用" << endl;
            system("pause");
            return 0;
            break;
        case 1:
            addpeople(&abs);
            break;
        case 2:
            dispalypeople(&abs);
            break;
        case 3:
            cout << "======" << order << endl;
            break;
        case 4:
            cout << "======" << order << endl;
            break;
        case 5:
            cout << "======" << order << endl;
            break;
        default:
            break;
        }
    }

    return 0;
}
