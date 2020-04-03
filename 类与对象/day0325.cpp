/*
 * @Author: Hellcat
 * @Date: 2020-03-25 11:57:26
 */
//Meyers Singleton设计模式
#include <iostream>
#include <cstdio>
using namespace std;

// class A {
// public:
//     static A& getInstance ();
// private:
//     A();
//     A(const A& rhs);
// };

// A& A::getInstance() {
//     static A a;
//     return a;
// }

// template <class T>
// inline const T& MyMin(const T& a, const T& b) {
//     return b < a ? b : a;
// }

// class stone {
// public:
//     stone(int w = 0, int h = 0, int we = 0) : m_w(w), m_h(h), m_weight(we) {}
//     bool operator < (const stone& rhs) const {
//         return m_weight < rhs.m_weight;
//     }
//     int get_weight() { return m_weight; }
// private:
//     int m_w, m_h, m_weight;
// };

// int main() {
//     stone s1(1, 2, 3), s2(5, 6, 7), s3;
//     s3 = MyMin<stone>(s1, s2);
//     cout<<s3.get_weight();
// }

// 继承方式
// 继承语法: class 子类 : 继承方式 父类

// class Base {
// public:
//     Base() { cout<<"Base构造函数"<<endl; }
//     ~Base() { cout<<"Base析构函数"<<endl; }
//     int m_A;
// protected: // 可以被继承 但是类外访问不到
//     int m_B;
// private:  // 不可继承
//     int m_C;
// }; // Size 12

// class Son1: public Base {
// public:
//     int m_D; // Size 4
//     void func() {
//         m_A = 10;
//         m_B = 10;
//         // m_C = 10; private不能继承
//     }
// };

// void test01() {
//     Son1 s1; // Size 16
//     // 基类中所有非静态成员属性都会被派生类继承下去
//     // 基类private访问不到 但确实被继承下去了
//     s1.m_A = 100;
//     // s1.m_B 保护 访问不到
//     cout<<"Size of Son = "<<sizeof(Son1)<<endl; // result is 16
// }

// class Son2: protected Base {
// public:
//     void fun() {
//         m_A = 100; // 保护
//         m_B = 100; // 保护
//         // m_C = 100;
//     }
// };

// void test02() {
//     Son2 s2;
//     // s2.m_A = 100; 保护权限 访问不到
//     //s2.m_B;
// }

// class Son3: private Base {
// public:
//     Son3() { cout<<"Son3构造函数"<<endl; }
//     ~Son3() { cout<<"Son3析构函数"<<endl; }
//     void fun() {
//         m_A = 100; // 私有成员
//         m_B = 100; // 私有成员
//         // m_C
//     }
// };

// void test03() {
//     Son3 s1;
//     // s1.m_A = 100;
//     // s1.m_B = 100;
// }

// class GrandSon3: public Son3 {
// public:
//     void fun() {
//         // m_A = 1000; // Son3中私有
//     }
// };

// int main() {
//     test03(); // 由内二外构造 由外到内析构
// }

// 继承中同名成员处理
class Base {
public:
    Base() { m_A = 100; }
    int m_A;
    static int m_B;
    void fun() { cout<<"这是Base的fun函数"<<endl; }
    void fun(int a) { cout<<"这是Base的带参同名fun"<<endl; }
    static void func() { cout<<"这是Base的static-func函数"<<endl; }
};
int Base::m_B = 200;

class Son: public Base {
public:
    Son() { m_A = 200; }
    int m_A;
    static int m_B;
    void fun() { cout<<"这是Son的fun函数"<<endl; }
    static void func() { cout<<"这是Son的static-func函数"<<endl; }
};
int Son::m_B = 50;

// 同名成员属性
void test01() {
    Son s;
    cout<<"Son 下 m_A = "<<s.m_A<<endl;
    cout<<"Base 下 m_A = "<<s.Base::m_A<<endl;
    Son s2;
    cout<<"(object)Son 下 m_B = "<<s.m_B<<endl;
    cout<<"(object)Base 下 m_B = "<<s.Base::m_B<<endl;
    cout<<"(class name) Base下 m_B = "<<Son::Base::m_B<<" == "<<Base::m_B<<endl;
    cout<<"(class name) Son下 m_B = "<<Son::m_B<<endl;
    s.fun();      // 派生类直接访问
    s.Base::fun(); // 基类加作用域
    s.Base::fun(100);
    s.func();
    s2.func();
    Base::func();
    Son::func();
}

int main() {
    test01();
}
