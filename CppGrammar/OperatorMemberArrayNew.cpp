/*
 * @Author: Hellcat
 * @Date: 2020-04-03 14:24:51
 */
#include <iostream>
using namespace std;

class Foo {
public:
    Foo() {
        cout<< "Foo ("<< ++ctorNum << ")"<<endl;
        m_data = 0;
    }
    ~Foo() {
        cout<< "~Foo ("<< ++dtorNum << ")"<<endl;
    }
    void* operator new[] (size_t size) noexcept {
        cout<< "Foo operator new" <<endl;
        return malloc(size);
    }
    void operator delete[](void* ptr, size_t size) {
        cout<< "Foo operator delete[]" <<endl;
        free(ptr);
    }
    static int ctorNum, dtorNum;
    int getData() { return m_data; }
private:
    int m_data;
};

int Foo::ctorNum = 0;
int Foo::dtorNum = 0;

int main() {
    Foo *p = new Foo[5];
    cout<<p[1].getData()<<endl;
    delete[] p;
}
