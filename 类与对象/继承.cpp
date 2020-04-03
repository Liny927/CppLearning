#include <cstdio>
#include <iostream>
using namespace std;

class Base {
public:
    int m_A;
protected: // 可以被继承 但是类外访问不到
    int m_B;
private:  // 不可继承
    int m_C;
}; // Size 12

class Son1 : public Base {
public:
    int m_D; // Size 4
    void func() {
        m_A = 10;
        m_B = 10;
        // m_C = 10; private不能继承
    }
};

void test01() {
    Son1 s1; // Size 16
    // 基类中所有非静态成员属性都会被派生类继承下去
    // 基类private访问不到 但确实被继承下去了
    s1.m_A = 100;
    // s1.m_B 保护 访问不到
    cout << "Size of Son = " << sizeof(Son1) << endl; // result is 16
}

class Son2 : protected Base {
public:
    void fun() {
        m_A = 100; // 保护
        m_B = 100; // 保护
        // m_C = 100;
    }
};

void test02() {
    Son2 s2;
    // s2.m_A = 100; 保护权限 访问不到
    //s2.m_B;
}

class Son3 : private Base {
public:
    void fun() {
        m_A = 100; // 私有成员
        m_B = 100; // 私有成员
        // m_C
    }
};

void test03() {
    Son3 s1;
    // s1.m_A = 100;
    // s1.m_B = 100;
}

class GrandSon3 : public Son3 {
public:
    void fun() {
        // m_A = 1000; // Son3中私有
    }
};

int main() {
    test01();
}
