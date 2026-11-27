/*
 * 编程练习 7-11
 * 定义一个基类 BaseClass，从它派生出 DerivedClass；
 * BaseClass 有成员函数 fn1()、fn2()，DerivedClass 也有 fn1()、fn2()。
 * 在主函数中声明一个 DerivedClass 的对象，分别用 DerivedClass 的对象、
 * 以及 BaseClass 和 DerivedClass 的指针来调用 fn1()、fn2()，观察运行结果。
 *
 * 编译运行：
 *   g++ 7-11.cpp -o 7-11.exe -Wall -Wextra -std=c++17 -fexec-charset=GBK
 *   ./7-11.exe
 */
#include <iostream>
using namespace std;

class BaseClass
{
public:
    void fn1() { cout << "BaseClass::fn1()" << endl; }
    void fn2() { cout << "BaseClass::fn2()" << endl; }
    // 注意：这里刻意不写 virtual —— 本讲考察的正是"同名隐藏 + 静态绑定"。
    // 如果把上面两行改成 virtual void fn1() / virtual void fn2()，
    // 那么第 2 组通过 BaseClass* 的调用也会执行 DerivedClass 的版本（多态）。
    virtual ~BaseClass() = default;
};

class DerivedClass : public BaseClass
{
public:
    // 与基类同名的函数会"隐藏"基类的同名函数（不是重载，参数表也相同）
    void fn1() { cout << "DerivedClass::fn1()" << endl; }
    void fn2() { cout << "DerivedClass::fn2()" << endl; }
};

// 对比组：把基类函数声明为 virtual 后的效果
class VBase
{
public:
    virtual void fn1() { cout << "VBase::fn1()" << endl; }
    virtual void fn2() { cout << "VBase::fn2()" << endl; }
    virtual ~VBase() = default;
};

class VDerived : public VBase
{
public:
    void fn1() override { cout << "VDerived::fn1()" << endl; }
    void fn2() override { cout << "VDerived::fn2()" << endl; }
};

int main()
{
    DerivedClass obj;

    cout << "1) 用 DerivedClass 对象直接调用：" << endl;
    obj.fn1();
    obj.fn2();

    cout << "2) 用 BaseClass* 指向派生类对象：" << endl;
    BaseClass *pb = &obj;
    pb->fn1();
    pb->fn2();

    cout << "3) 用 DerivedClass* 指向派生类对象：" << endl;
    DerivedClass *pd = &obj;
    pd->fn1();
    pd->fn2();

    cout << "4) 通过对象强行调用被隐藏的基类版本（类名 + ::）：" << endl;
    obj.BaseClass::fn1();
    obj.BaseClass::fn2();

    cout << "5) 对比：基类函数加 virtual 后，基类指针也调用派生类版本：" << endl;
    VDerived vobj;
    VBase *vb = &vobj;
    vb->fn1();
    vb->fn2();

    return 0;
}
