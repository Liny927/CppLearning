/*
 * @Author: Hellcat
 * @Date: 2020-03-28 17:47:46
 */
// ��̬��̬: ���� ���������
// ��̬��̬: ������ �麯��ʵ������ʱ��̬��̬
// ��̬��̬��������:
// 1.�м̳й�ϵ
// 2.������д�����е��麯��
// ʹ��:
// ����ָ�������ָ���������
#include <bits/stdc++.h>
using namespace std;

class Animal {
public:
    virtual void speak() { // ָ��
        cout<<"������˵��"<<endl;
    }
};

class Cat: public Animal {
public:
    virtual void speak() {
        cout<<"è��˵��"<<endl;
    }
};

// ��ַ��� ����׶�ȷ��������ַ (���ຯ������)
// ��ַ��� (�麯��)
void doSpeak(Animal &ani) {
    ani.speak();
}

void test01() {
    Cat cat;
    doSpeak(cat);
}

void test02() {
    cout<<"sizeof Animal = "<<sizeof(Animal)<<endl;;
}

int main() {
    //test01();
    test02();
}
