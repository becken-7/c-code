/*
 * 编程练习 7-15
 * 原题：下面的程序能得到预期的结果吗？如何避免类似问题的发生？
 *
 *   Derived *pd = new Derived;
 *   pd->x = 1; pd->y = 2.0f;
 *   void *pv = pd;
 *   Base2 *pb = static_cast<Base2 *>(pv);
 *   cout << pd->y << " " << pb->y << endl;
 *   delete pb;
 *
 * 答案：不能。void* 中转把"多继承的指针调整"信息弄丢了。
 *       static_cast<Base2*>(void*) 只是把地址原样重新解释，并不会加上
 *       Base2 子对象相对 Derived 起始地址的偏移量，pb 实际仍指向 Base1 子对象。
 *
 * 本文件演示错误写法与三种正确写法；为避免未定义行为，不执行原题的 delete pb。
 * 编译运行：
 *   g++ 7-15.cpp -o 7-15.exe -Wall -Wextra -std=c++17 -fexec-charset=GBK
 *   ./7-15.exe
 */
#include <iostream>
using namespace std;

struct Base1 { int x; };
struct Base2 { float y; };
struct Derived : Base1, Base2 {};

int main()
{
    Derived *pd = new Derived;
    pd->x = 1;
    pd->y = 2.0f;

    void *pv = pd;                                 // ① 地址原样保存，类型信息全部丢失
    Base2 *bad = static_cast<Base2 *>(pv);          // ② 错的：没有做指针偏移调整
    Base2 *ok1 = pd;                                // ③ 正确：隐式转换，编译器自动加偏移
    Base2 *ok2 = static_cast<Base2 *>(pd);          // ④ 正确：在"有类型"的指针之间转换

    cout << "pd          = " << pd << endl;
    cout << "bad(void*)  = " << bad << "  <-- 与 pd 相同，偏移丢了" << endl;
    cout << "ok (Base2*) = " << ok1 << endl;
    cout << "ok1 == ok2 ? " << (ok1 == ok2 ? "yes" : "no") << endl;

    cout << "pd->y       = " << pd->y << endl;
    cout << "bad->y      = " << bad->y << "  <-- 把 Base1::x 的 4 字节当成 float 读" << endl;
    cout << "ok1->y      = " << ok1->y << endl;

    // 原题还有一句 delete pb：
    //   1) pb 指向的并不是 new 返回的地址；
    //   2) Base2 没有虚析构函数，通过基类指针删除派生类对象只析构了一部分。
    // 这两点都是未定义行为（可能堆损坏、崩溃，也可能"看起来没事"）。
    // 正确做法：用 new 得到的原始指针删除；若一定要用基类指针，基类必须有虚析构。
    delete pd;

    return 0;
}
