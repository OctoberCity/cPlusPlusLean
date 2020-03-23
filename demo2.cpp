#include <iostream>
#include<string>
using namespace std;
int resuse = 42;
int main()
{
    // char c;
    // c = 'a';
    wchar_t c2 = L'中';
    std::string book("this is book STRING");
    std::cout << book << "==" << c2 << std::endl;
    double price = 109.99, discount = price * 0.16;
    std::cout << discount << "==" << std::endl;
    // wchar_t wt[] = "中国伟大复兴梦";   //大写字母L告诉编译器为"中"字分配两个字节的空间
    // std::cout << wt << std::endl;               //使用wcout来代替cout输出宽字符
    // 使用列表初始化如果存在数据丢失会报错，花括号初始
    //使用花括号
    long double ld = 3.14566799;
    // int a{ld} , b={ld};
    int c(ld), d = ld;

    // 默认初始化 一般会给默认值（隐式初始化），但是函数体中的默认初始化将不会被支持。
    int wage;
    double salary = wage = 9999.999;
    int i = 3.14;

    int sum = 0;
    for (int val = 1; val <= 10; ++val)
    {
        sum += val;
    }
    std::cout << "和是" << sum << std::endl;

    int resuse = 0;
    std::cout <<"显示获取全局作用域变量"<<::resuse<<"获取块级作用域变量"<<resuse<< std::endl;
    //  int ip =100,sum9 =0;
    //  for(int ip =0 ;ip !=10;++ip)
    //     sum9 +=ip;
    //    ;
    //   std::cout << ip << ""<<sum9<<std::endl; 

    // 引用reference,引用即别名
    int ival =1024;
    int &refval = ival;
    ++ival;
    std::cout << "元值是"<< ival << "refervalue is : "<< refval <<std::endl;
     --refval;
    std::cout << "元值是"<< ival << "refervalue is : "<< refval <<std::endl;
    string  str = "helloworld";
    cout<< str<<endl;
    return 0;
}

/**
 * warn:初始化含义是创建变量赋予值，赋值是将原来的值剔除，换新的值
 * 
 * **/
