/*
 * @Author: Hellcat
 * @Date: 2020-03-25 11:57:26
 */
//Meyers Singleton���ģʽ
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

// �̳з�ʽ
// �̳��﷨: class ���� : �̳з�ʽ ����

// class Base {
// public:
//     Base() { cout<<"Base���캯��"<<endl; }
//     ~Base() { cout<<"Base��������"<<endl; }
//     int m_A;
// protected: // ���Ա��̳� ����������ʲ���
//     int m_B;
// private:  // ���ɼ̳�
//     int m_C;
// }; // Size 12

// class Son1: public Base {
// public:
//     int m_D; // Size 4
//     void func() {
//         m_A = 10;
//         m_B = 10;
//         // m_C = 10; private���ܼ̳�
//     }
// };

// void test01() {
//     Son1 s1; // Size 16
//     // ���������зǾ�̬��Ա���Զ��ᱻ������̳���ȥ
//     // ����private���ʲ��� ��ȷʵ���̳���ȥ��
//     s1.m_A = 100;
//     // s1.m_B ���� ���ʲ���
//     cout<<"Size of Son = "<<sizeof(Son1)<<endl; // result is 16
// }

// class Son2: protected Base {
// public:
//     void fun() {
//         m_A = 100; // ����
//         m_B = 100; // ����
//         // m_C = 100;
//     }
// };

// void test02() {
//     Son2 s2;
//     // s2.m_A = 100; ����Ȩ�� ���ʲ���
//     //s2.m_B;
// }

// class Son3: private Base {
// public:
//     Son3() { cout<<"Son3���캯��"<<endl; }
//     ~Son3() { cout<<"Son3��������"<<endl; }
//     void fun() {
//         m_A = 100; // ˽�г�Ա
//         m_B = 100; // ˽�г�Ա
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
//         // m_A = 1000; // Son3��˽��
//     }
// };

// int main() {
//     test03(); // ���ڶ��⹹�� ���⵽������
// }

// �̳���ͬ����Ա����
class Base {
public:
    Base() { m_A = 100; }
    int m_A;
    static int m_B;
    void fun() { cout<<"����Base��fun����"<<endl; }
    void fun(int a) { cout<<"����Base�Ĵ���ͬ��fun"<<endl; }
    static void func() { cout<<"����Base��static-func����"<<endl; }
};
int Base::m_B = 200;

class Son: public Base {
public:
    Son() { m_A = 200; }
    int m_A;
    static int m_B;
    void fun() { cout<<"����Son��fun����"<<endl; }
    static void func() { cout<<"����Son��static-func����"<<endl; }
};
int Son::m_B = 50;

// ͬ����Ա����
void test01() {
    Son s;
    cout<<"Son �� m_A = "<<s.m_A<<endl;
    cout<<"Base �� m_A = "<<s.Base::m_A<<endl;
    Son s2;
    cout<<"(object)Son �� m_B = "<<s.m_B<<endl;
    cout<<"(object)Base �� m_B = "<<s.Base::m_B<<endl;
    cout<<"(class name) Base�� m_B = "<<Son::Base::m_B<<" == "<<Base::m_B<<endl;
    cout<<"(class name) Son�� m_B = "<<Son::m_B<<endl;
    s.fun();      // ������ֱ�ӷ���
    s.Base::fun(); // �����������
    s.Base::fun(100);
    s.func();
    s2.func();
    Base::func();
    Son::func();
}

int main() {
    test01();
}
