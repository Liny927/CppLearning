#include <iostream>
using namespace std;

class Person {
public:
	//无参（默认）构造函数
	Person() {
		cout << "调用了无参构造函数!" << endl;
	}
	//有参构造函数
	Person(int age, int height) {
		cout << "调用了有参构造函数!" << endl;
		m_age = age;
		m_height = new int(height);
	}
	//拷贝构造函数  
	Person(const Person& p) {
		cout << "调用了深拷贝构造函数!" << endl;
		//如果不利用深拷贝在堆区创建新内存，会导致浅拷贝带来的重复释放堆区问题
		m_age = p.m_age;
		//编译器默认实现的浅拷贝(会存在同一内存重复释放的问题)
		//m_height = p.m_height;
		//手动实现的深拷贝
		m_height = new int(*p.m_height);
	}
	//析构函数
	~Person() {
		cout << "调用了析构函数!" << endl;
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
	cout << "调用了重载的 = " << endl;
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
	cout << "p1的年龄： " << p1.m_age << " 身高： " << *p1.m_height << endl;
	cout << "p2的年龄： " << p2.m_age << " 身高： " << *p2.m_height << endl;
	cout << "p3的年龄： " << p3.m_age << " 身高： " << *p3.m_height << endl;
}

void test02() {
	Person p4(18, 180);
	AddScore(p4);
	cout << "p4的年龄： " << p4.m_age << " 身高： " << *p4.m_height << endl;
	// 如果没有重载"=" 那么也是简单的浅拷贝
	Person p5;
	p5 = AddScore(p4);
	cout << "p5的年龄： " << p5.m_age << " 身高： "<< *p5.m_height << endl;
}

int main() {
	test01();
	test02();
	return 0;
}
