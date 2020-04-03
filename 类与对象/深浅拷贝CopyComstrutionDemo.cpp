#include <iostream>
using namespace std;

class Person {
public:
	//�޲Σ�Ĭ�ϣ����캯��
	Person() {
		cout << "�������޲ι��캯��!" << endl;
	}
	//�вι��캯��
	Person(int age, int height) {
		cout << "�������вι��캯��!" << endl;
		m_age = age;
		m_height = new int(height);
	}
	//�������캯��  
	Person(const Person& p) {
		cout << "������������캯��!" << endl;
		//�������������ڶ����������ڴ棬�ᵼ��ǳ�����������ظ��ͷŶ�������
		m_age = p.m_age;
		//������Ĭ��ʵ�ֵ�ǳ����(�����ͬһ�ڴ��ظ��ͷŵ�����)
		//m_height = p.m_height;
		//�ֶ�ʵ�ֵ����
		m_height = new int(*p.m_height);
	}
	//��������
	~Person() {
		cout << "��������������!" << endl;
		if (m_height != nullptr)
		{
			delete m_height;
		}
	}
	void setScore(int m_age, int* m_height);
	Person& operator = (const Person& p);
public:
	int m_age;
	int* m_height;
};

Person& Person::operator = (const Person& p) {
	cout << "���������ص� = " << endl;
	m_age = p.m_age;
	if (this->m_height) 
		delete[]this->m_height;
	this->m_height = new int(*p.m_height);
	return *this;
}

void Person::setScore(int m_age, int* m_height) {
	this->m_age = ++m_age;
	*(this->m_height) = ++*(m_height);
}

Person AddScore(Person p) {
	p.setScore(p.m_age, p.m_height);
	return p;
}

void test01() {
	Person p1(18, 180);
	Person p2(p1);
	Person p3 = p2;
	cout << "p1�����䣺 " << p1.m_age << " ��ߣ� " << *p1.m_height << endl;
	cout << "p2�����䣺 " << p2.m_age << " ��ߣ� " << *p2.m_height << endl;
	cout << "p3�����䣺 " << p3.m_age << " ��ߣ� " << *p3.m_height << endl;
}

void test02() {
	Person p4(18, 180);
	AddScore(p4);
	cout << "p4�����䣺 " << p4.m_age << " ��ߣ� " << *p4.m_height << endl;
	// ���û������"=" ��ôҲ�Ǽ򵥵�ǳ����
	Person p5;
	p5 = AddScore(p4);
	cout << "p5�����䣺 " << p5.m_age << " ��ߣ� "<< *p5.m_height << endl;
}

int main() {
	test01();
	test02();
	return 0;
}
