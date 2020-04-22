#include<iostream>
using namespace std;
// Recursive 递归算法



// 计算n!的递归程序
int func(int i){
 if(i==0){ 
    cout<<0<<"的阶乘是"<<1<< endl;
    return 1;
 }
 int sum = i*func(i-1);
 cout<<i<<"的阶乘是"<<sum<< endl;
 return sum;
}

int  main(){
    int i =4;
    func(i);
    return 0;
} 