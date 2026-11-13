// 5-13  友元函数与友元类（类的定义与实现，第一个文件）
// 关系：
//   1. Y 的成员函数 g(X*) 是 X 的友元函数，实现对 X 的成员 i 加 1；
//   2. Z 是 X 的友元类，其成员函数 f(X*) 实现对 X 的成员 i 加 5；
//   3. 函数 h(X*) 是 X 的友元函数，实现对 X 的成员 i 加 10。
#ifndef CLASSES_H
#define CLASSES_H

class X;                                

class Y                                
{
public:
    void g(X* x);                       
};

class Z
{
public:
    void f(X* x);
};

void h(X* x);                           

class X
{
private:
    int i;                              
public:
    X(int v = 0) : i(v) {}              
    int get() const { return i; }       
    friend void Y::g(X*);               
    friend class Z;                     
    friend void h(X*);                  
};


inline void Y::g(X* x) { x->i += 1;  }  
inline void Z::f(X* x) { x->i += 5;  }  
inline void h(X* x)    { x->i += 10; }  

#endif
