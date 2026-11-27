/*
 * 编程练习 7-5
 * 定义一个基类 Shape，在此基础上派生出 Rectangle 和 Circle，
 * 二者带有 getArea() 函数计算对象的面积；
 * 使用 Rectangle 类创建一个派生类 Square。
 * 自行完善各类的数据成员和成员函数以及主函数测试语句。
 *
 * 编译运行（沿用本机 GBK 控制台配置）：
 *   g++ 7-5.cpp -o 7-5.exe -Wall -Wextra -std=c++17 -fexec-charset=GBK
 *   ./7-5.exe
 */
#include <iostream>
#include <string>
using namespace std;

const double PI = 3.14159265358979323846;

// 基类 Shape：只放各图形共有的东西（名字 + 求面积接口）
class Shape
{
public:
    explicit Shape(const string &n = "Shape") : name(n) {}
    virtual ~Shape() = default;                  // 基类析构函数写成虚函数，方便以后用 Shape* 删除对象
    virtual double getArea() const { return 0.0; } // 虚函数：派生类可以改写自己的面积算法
    void show() const
    {
        cout << name << " 的面积 = " << getArea() << endl;
    }

protected:
    string name;                                 // protected：派生类可见，类外不可见
};

// 公有继承：Rectangle 是一种 Shape
class Rectangle : public Shape
{
public:
    Rectangle(double w, double h) : Shape("Rectangle"), width(w), height(h) {}
    double getArea() const override { return width * height; }
    double getWidth() const { return width; }
    double getHeight() const { return height; }

protected:                                       // 让下一级的 Square 能直接复用
    double width, height;
};

class Circle : public Shape
{
public:
    explicit Circle(double r) : Shape("Circle"), radius(r) {}
    double getArea() const override { return PI * radius * radius; }

private:
    double radius;
};

// Square 是特殊的 Rectangle：边长相等，直接复用父类的宽高和 getArea()
class Square : public Rectangle
{
public:
    explicit Square(double side) : Rectangle(side, side)
    {
        name = "Square";                         // 改写继承来的 protected 成员
    }
    // 这里故意不再写 getArea()：正方形面积 = 宽 * 高，Rectangle 的实现已经够用，
    // 这正体现了继承的价值 —— 派生类自动获得并复用基类代码。
};

int main()
{
    Rectangle rect(4, 5);
    Circle circle(2);
    Square square(3);

    // 1) 用各自对象调用
    rect.show();
    circle.show();
    square.show();

    // 2) 通过基类指针统一调用，验证"多态"：同一条语句按对象真实类型算面积
    cout << "\n-- 通过 Shape* 统一调用 --" << endl;
    Shape *shapes[3] = {&rect, &circle, &square};
    for (const Shape *p : shapes)
    {
        cout << "Shape* -> area = " << p->getArea() << endl;
    }

    return 0;
}
