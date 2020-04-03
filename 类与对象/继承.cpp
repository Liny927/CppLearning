#include <cstdio>
#include <iostream>
using namespace std;

class Base {
public:
    int m_A;
protected: // ���Ա��̳� ����������ʲ���
    int m_B;
private:  // ���ɼ̳�
    int m_C;
}; // Size 12

class Son1 : public Base {
public:
    int m_D; // Size 4
    void func() {
        m_A = 10;
        m_B = 10;
        // m_C = 10; private���ܼ̳�
    }
};

void test01() {
    Son1 s1; // Size 16
    // ���������зǾ�̬��Ա���Զ��ᱻ������̳���ȥ
    // ����private���ʲ��� ��ȷʵ���̳���ȥ��
    s1.m_A = 100;
    // s1.m_B ���� ���ʲ���
    cout << "Size of Son = " << sizeof(Son1) << endl; // result is 16
}

class Son2 : protected Base {
public:
    void fun() {
        m_A = 100; // ����
        m_B = 100; // ����
        // m_C = 100;
    }
};

void test02() {
    Son2 s2;
    // s2.m_A = 100; ����Ȩ�� ���ʲ���
    //s2.m_B;
}

class Son3 : private Base {
public:
    void fun() {
        m_A = 100; // ˽�г�Ա
        m_B = 100; // ˽�г�Ա
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
        // m_A = 1000; // Son3��˽��
    }
};

int main() {
    test01();
}
