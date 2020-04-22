#pragma once
#include <iostream>
#include <Work.h>
#include <string>
using namespace std;
class Employee : public Work
{
private:
    /* data */
public:
    Employee(int id, string name, int departnumber);
    ~Employee();

    //extends 
    virtual void showInfo();

};