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

// 新增联系人
void addpeople(AddressBooks *abs)
{
    if (abs->peoplenum >= MAX)
    {
        cout << "已经到达最大值" << endl;
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
    cout << "请输入联系人年龄" << endl;
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
// 显示所有的联系人
void dispalypeople(AddressBooks *abs)
{
    if (abs->peoplenum <= 0)
    {
        cout << "无数据" << endl;
        return;
    }
    cout << "\t姓名\t性别\t年龄\t家庭住址\t电话号码" << endl;
    for (int i = 0; i < abs->peoplenum; i++)
    {
        string sex = abs->addressp[i].sex == 0 ? "女" : "男";
        cout << "\t" << abs->addressp[i].name << "\t" << sex << "\t" << abs->addressp[i].age << "\t" << abs->addressp[i].add << "\t" << abs->addressp[i].phone << endl;
    };
}

// 查询一个联系下标
int findOnepeopleIndex(AddressBooks *abs, string name)
{
    int index = -1;
    for (int i = 0; i < abs->peoplenum; i++)
    {
        if (abs->addressp[i].name == name)
        {
            index = i;
            break;
        }
    }
    return index;
};

void dispalyOneProple(AddressBooks *abs)
{
    string name;
    if (abs->peoplenum <= 0)
    {
        cout << "暂无数据" << endl;
        return;
    };
    cout << "请输入你要查询的联系人名字" << endl;
    cin >> name;
    int index = findOnepeopleIndex(abs, name);
    if (index < 0)
    {
        cout << "查无此人" << endl;
    }
    else
    {
        string sex = abs->addressp[index].sex == 0 ? "女" : "男";
        cout << "\t" << abs->addressp[index].name << "\t" << sex << "\t" << abs->addressp[index].age << "\t" << abs->addressp[index].add << "\t" << abs->addressp[index].phone << endl;
    }
};

// 修改一个联系人
void update(AddressBooks *abs){
    string name;
    if (abs->peoplenum <= 0)
    {
        cout << "暂无数据" << endl;
        return;
    };
    cout << "请输入你要修改的联系人名字" << endl; 
        cin >> name;
    int index = findOnepeopleIndex(abs, name);
    if (index < 0)
    {
        cout << "无此人" << endl;
        return;
    }
       string name;
    string phone;
    int age;
    int sex;
    string add;
    cout << "请输入联系人新名字" << endl;
    cin >> name;
    abs->addressp[index].name = name;
    cout << "请输入联系人新年龄" << endl;
    cin >> age;
    abs->addressp[index].age = age; 
    cout << "联系人联系新地址" << endl;
    cin >> add;
    abs->addressp[index].add = add;
    cout << "请输入联系人新联系电话" << endl;
    cin >> phone;
    abs->addressp[index].phone = phone;
    abs->peoplenum++;
    cout << "修改成功" << endl;
};

// 删除一个联系人
void deleteOnePeople(AddressBooks *abs)
{
    string name;
    if (abs->peoplenum <= 0)
    {
        cout << "暂无数据" << endl;
        return;
    };
    cout << "请输入你要删除的联系人名字" << endl;
    cin >> name;
    int index = findOnepeopleIndex(abs, name);
    if (index < 0)
    {
        cout << "无此人" << endl;
    }
    else
    {
        // 真删除的地方
        for (int i = index; i < abs->peoplenum; i++)
        {
            abs->addressp[i] = abs->addressp[i+1];
        }
         --abs->peoplenum;
        cout << "删除成功" << endl;
    }
}

// 显示菜单
void printmenu()
{
    cout << "============================" << endl;
    cout << "=======1 /t 添加联系人=======" << endl;
    cout << "=======2 /t 显示联系人=======" << endl;
    cout << "=======3 /t 查找联系人=======" << endl;
    cout << "=======4 /t 修改联系人=======" << endl;
    cout << "=======5 /t 清空联系人=======" << endl;
    cout << "=======6 /t 删除联系人=======" << endl;
};
int main()
{
    int order;
    AddressBooks abs;
    abs.peoplenum = 0;

    while (true)
    {

        printmenu();
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
            dispalyOneProple(&abs);
            break;
        case 4:
            cout << "======" << order << endl;
            break;
        case 5:
            cout << "======" << order << endl;
            break;
        case 6:
            deleteOnePeople(&abs);
            break;
        default:
            break;
        }
    }

    return 0;
}
