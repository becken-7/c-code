// 6-20  SimpleCircle 简单圆类
// 题目：数据成员 int *itsRadius 为一个指向其半径值的指针，存放其半径值。
//       设计对数据成员的各种操作，给出这个类的完整实现并测试这个类。
//
// 知识点：类含有指针成员时，必须遵守"三法则"(Rule of Three)：
//         析构函数 + 拷贝构造函数 + 赋值运算符，且都要做深拷贝。
#include <iostream>
using namespace std;

const double PI = 3.14159265358979323846;

class SimpleCircle {
private:
    int *itsRadius;              // 指向存放半径值的动态内存
public:
    // ---- 构造：为指针成员申请内存 ----
    SimpleCircle()          { itsRadius = new int(0); }   // 默认半径 0
    SimpleCircle(int r)     { itsRadius = new int(r); }   // 指定半径

    // ---- 拷贝构造：深拷贝（不能只复制地址，否则两个对象共用一块内存）----
    SimpleCircle(const SimpleCircle &c) {
        itsRadius = new int(*(c.itsRadius));
    }

    // ---- 赋值运算符：深拷贝，并处理自赋值 ----
    SimpleCircle& operator=(const SimpleCircle &c) {
        if (this != &c) {                    // 防止 c = c 时出错
            *itsRadius = *(c.itsRadius);    // 复用已有内存，只改里面的值
        }
        return *this;
    }

    // ---- 析构：释放动态内存，防止内存泄漏 ----
    ~SimpleCircle() { delete itsRadius; }

    // ---- 对数据成员的各种操作 ----
    int    getRadius()    const { return *itsRadius; }                        // 读半径
    void   setRadius(int r)    { *itsRadius = r; }                           // 改半径
    double getArea()      const { return PI * (*itsRadius) * (*itsRadius); }  // 面积
    double getPerimeter() const { return 2 * PI * (*itsRadius); }             // 周长
    void   print()        const {
        cout << "半径=" << *itsRadius
             << "  面积=" << getArea()
             << "  周长=" << getPerimeter() << endl;
    }
};

int main() {
    SimpleCircle c1;             // 默认构造：半径 0
    SimpleCircle c2(5);          // 带参构造：半径 5
    SimpleCircle c3(c2);         // 拷贝构造
    SimpleCircle c4;
    c4 = c2;                     // 赋值运算

    cout << "c1: "; c1.print();
    cout << "c2: "; c2.print();
    cout << "c3(由c2拷贝): "; c3.print();
    cout << "c4(由c2赋值): "; c4.print();

    c1.setRadius(3);
    cout << "把 c1 半径改为 3: "; c1.print();
    cout << "c1.getRadius() = " << c1.getRadius() << endl;

    // 验证深拷贝：修改 c2 不会影响 c3、c4
    c2.setRadius(10);
    cout << "把 c2 半径改为 10 之后：" << endl;
    cout << "  c2: "; c2.print();
    cout << "  c3: "; c3.print();
    cout << "  c4: "; c4.print();

    return 0;
}
