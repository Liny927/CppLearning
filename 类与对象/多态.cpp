/*
 * @Author: Hellcat
 * @Date: 2020-03-28 17:47:46
 */
// 静态多态: 函数 运算符重载
// 动态多态: 派生类 虚函数实现运行时动态多态
// 动态多态满足条件:
// 1.有继承关系
// 2.子类重写父类中的虚函数
// 使用:
// 父类指针或引用指向子类对象
#include <bits/stdc++.h>
using namespace std;

class Animal {
public:
    virtual void speak() { // 指针
        cout<<"动物在说话"<<endl;
    }
};

class Cat: public Animal {
public:
    virtual void speak() {
        cout<<"猫在说话"<<endl;
    }
};

// 地址早绑定 编译阶段确定函数地址 (父类函数非虚)
// 地址晚绑定 (虚函数)
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
