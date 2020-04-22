#pragma once
#include <iostream>
#include <Work.h>
#include <string>
using namespace std;
class Boss : public Work
{
private:
    /* data */
public:
    Boss(int id, string name, int departnumber);
    ~Boss();

    //extends 
    virtual void showInfo(); 

    string getname();
};