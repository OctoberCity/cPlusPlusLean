//斐波拉契
// 后面两数是前面两数的和 第一项是1，第二项是1，第三项是2，第四项是3，第四项是5
#include<iostream>
using namespace std;


int func(int num){
    if(num<=0){
        return 0;
    }
    if(num==1 || num ==2){ 
        return 1;
    }
    int sum = func(num-1)+func(num-2);
    return sum ;
}

int main(){
    int num =10;
    for(int i =1 ;i<=num;i++){
       int sum = func(i);
    cout<<"fb("<<i<<")结果是"<<sum<<endl;
    }
    return 0;
}