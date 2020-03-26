# cPlusPlusLean


#### 内存分区模型
- 代码区 ：存放函数体二进制代码
- 全局区 ：全局变量，静态变量，常量
- 栈区：编译区自动分配释放，局部变量，函数的参数
- 堆区：程序员可管理的，操作释放，否则在系统结束时，释放。

#### 编译程序各种状态
#### 1. 程序运行前（编译之后exe文件）
代码区：存放 共享的，只读的，cpu执行的机器指令。

全局区：存放 常量，全局变量，静态变量（通过他们的地址可以看出存放地址端得差别）

#### 2. 程序运行时

栈区：存放局部，函数参数等
> 注意不要返回局部变量的地址，局部变量存放栈中，随函数执行完，局部变量会被释放，地址失效。
```
int * function(){
    int num =0;
    return &num
}
不要这样做
```

堆区：由程序猿开辟数据空间，由程序猿释放，如果不释放，那么系统结束时，会帮助释放，常使用new 开辟堆数据，使用delete释放；
```
double * f(){
    double * p  = new double(10);
    int * arr = new int[10];
    delete[] arr; // 删除数组
    return p;
}

void test(){
  double * c = f();
  delete c;
}
``` 

------------

## 引用

- 给变量设置别名
- 基本使用："&" => 数据类型 &别名 = 被引用的别名 列子：
  ```
  int num = 0; 
  int &othername = num;
  ``` 
- 实质是指针

引用的特点：

1. 引用必须初始化
2. 引用初始化之后不能改嫁,"指鸡随鸡，指狗随狗"

引用作为函数参数
```
简化指针在函数的表达
// 值传递
function test1(int a,int b);
// 地址传递
function test2(int *a,int *b);
// 引用传递
function test3(int &a,int &b);
int a= 10;
int b =15;
test1(a,b);
test2(&a,&b);
test(a,b);
```

引用作为函数返回值
```
实质是返回被引用的变量，因此可以作为左值
int& function test(){  //不要返回局部变量存在栈区，随函数消亡
  int num =10;
  return num;
}

int& function test2(){ // static 修饰之后存在全局区
  static int num =10;
  return num;
}

test2()=1999;//左值==》 num =1999;
```

引用本质
> 本质是指针常量，指针指向的方向不可改（引用初始化之后不能改嫁,"指鸡随鸡，指狗随狗"），指向的的值value可以改

常量引用
这下连value都不能修改了
```
function test(const int &val){
  val =1000  ///不行
}  
int num =10000;
const int &newnum = num // newnum 指向不能变，value不能变
```

## 函数

函数默认参数，不传就用默认值
```
void function test(int a=10,int b=20,int c=30); 
但是默认参数一旦在函数参数列表存在，那么该参数之后的参数都必须有默认
void function test(int a=10,int b,int c);//这是错误的，b,c都是需要默认参数
void function test(int a,int b =10,int c);//c需要默认参数
```
函数的声明和定义中有且只有一个对默认参数的定义。
```
void function test(int a=10,int b,int c); //函数声明

void function test(int a,int b,int c){ // 函数定义

}
```
函数占位参数
 
一般来说函数参数列表：function(数据类型 参数名字)
但是函数占位参数可以省略参数名称。为什么叫占位参数呢？因为调用函数的时候---占位参数的参数也要传---，**一定要传**
```
void function test(int a , int);
test(a,b);
test(a);//错误,占位参数也要给面子滴！！！
占位参数也是可以由默认参数
``` 
函数重载

一句话：同一***作用域**下，***返回值类型***相同的，***参数列表***不同（顺序，数量，数据类型）***同名***函数，称之为函数重载。
```
void function test(int a,int b,double c);
void function test(int a=10,double b,int c);
void function test(int b,int c);
void function test(int a=10,int b,float c);
```
函数重载之坑之--参数是引用
```
引用和常量引用不一样
void function test(int &a);
void function test(const int &a);
int n= 10;
test(n)==> int &a 
test(10)==> const int &a

引用是要有可读可写的变量的，字面量10不是。
```

函数重载之坑之--参数有默认参数

默认参数可以允许参数不传。那么这种“重载”能生效吗？
```
void function test(int a,int b =10)
void function test(int a,int b)
test(10,18)===>error 这种默认参数相当于没有参数。。。。
```

## 文件操作 嘀嘀嘀




打开方式
option|意义
-|:-:
||
||
|| 