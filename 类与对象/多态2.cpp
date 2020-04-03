/*
 * @Author: Hellcat
 * @Date: 2020-03-31 12:36:21
 */
// 思考点: 静态绑定or动态绑定
#include <iostream>
using namespace std;

class myA {
public:
    virtual void vfunc1() { cout<<"successA"<<endl; };
    virtual void vfunc2() {};
            void func1() {};
            void func2() {};
private:
    int m_data1, m_data2;
};

class myB: public myA {
public:
    virtual void vfunc1() { cout<<"successB"<<endl; };
            void func2() {};
private:
    int m_data3;
};

class myC: public myB {
public:
    virtual void vfunc1() { cout<<"successC"<<endl; };
            void func2() {};
private:
    int m_data1, m_data4;
};

int main() {
    auto *p = new myC;
    auto *p2 = new myB;
    auto *p3 = new myA;
    p->vfunc1();
    p2->vfunc1();
    p3->vfunc1();
}
