// 5-13  测试主函数（第二个文件）
// 要求：类在一个文件中定义和实现，main() 函数在另一个文件中实现。
#include <iostream>
#include "5-13_classes.h"      
using namespace std;

int main()
{
    X x(0);                                    
    Y y;
    Z z;

    cout << "初始值        i = " << x.get() << endl;

    y.g(&x);                                   // Y 的成员函数（友元成员）：i 加 1
    cout << "y.g(&x) 后    i = " << x.get() << endl;

    z.f(&x);                                   // 友元类 Z 的成员函数：i 加 5
    cout << "z.f(&x) 后    i = " << x.get() << endl;

    h(&x);                                     // 友元函数：i 加 10
    cout << "h(&x) 后      i = " << x.get() << endl;

    return 0;
}
