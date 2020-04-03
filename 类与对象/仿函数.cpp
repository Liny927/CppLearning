/*
 * @Author: Hellcat
 * @Date: 2020-03-25 18:00:25
 */
#include <iostream>
#include <string>
using namespace std;

class MyPrint {
public:
    void operator() (string txt) {
        cout<<txt<<endl;
    }
};

class MyAdd {
public:
    int operator() (int a, int b) {
        return a + b;
    }
};

void test01() {
    MyPrint m1;
    m1("Hello World");
    MyAdd m2;
    cout<<m2(1, 1)<<endl;
    // 匿名函数对象
    cout<<MyAdd() (1, 1) <<endl;
}

int main() {
    test01();
}
