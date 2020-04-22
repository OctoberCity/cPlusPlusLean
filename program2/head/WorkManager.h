#pragma once
#include <iostream>
#include <Work.h>
#include <Employee.h>
#include <fstream>
#define FILENAME "database.txt"
using namespace std;

class WorkManager
{

public:
    // 构造函数
    WorkManager();

    // 析构函数
    ~WorkManager();

    void exitProcess();

    // 显示菜单
    void menu();
    // 添加员工
    void addWork();
    // 显示所有员工
    void showAllWork();
    // 持久化数据到内存
    void saveDataToFile();
    // 初始化文件数据
    void initFileData();
    //获取员工数，用来开辟初始化的数组数据
    void initWorkNum();
    // 存放的员工数组
    Work **workArr;
    // 员工人数
    int worknum;
    bool isEmptyFile;
};