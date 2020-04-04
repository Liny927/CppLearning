/*
 * @Author: Hellcat
 * @Date: 2020-04-03 14:24:51
 */
#include <iostream>
using namespace std;

class Foo { // 16
public:
    Foo(): m_id(0) {
        cout<<"Foo("<<++ctorNum<<")"<<", this = "<<this<<endl;
    }
    Foo(int i): m_id(i) {
        cout<<"Foo("<<++ctorNum<<")"<<endl;
    }
    ~Foo() {
        cout<<"~Foo("<<++dtorNum<<")"<<", this = "<<this<<endl;
    }
    static int ctorNum, dtorNum;
    static void* operator new(size_t size);
    static void operator delete(void* pdead, size_t size);
    static void* operator new[](size_t size);
    static void operator delete[](void* pdead, size_t size);
private:
    int m_id; // 4
    long m_data; // 4
    char* m_str; // 8
};

void* Foo::operator new(size_t size) {
    auto p = (Foo*)malloc(size);
    cout<<"Foo operator new"<<endl;
    return p;
}

void Foo::operator delete(void* pdead, size_t size) {
    cout<<"Foo operator delete"<<endl;
    free(pdead);
}

void* Foo::operator new[](size_t size) {
    Foo* p = (Foo*)malloc(size);
    cout<<"Foo operator new[]"<<endl;
    cout<<"SIZE: "<<size<<endl; // 56 = 16*3 + 8
    return p;
}

void Foo::operator delete[](void* pdead, size_t size) {
    cout<<"Foo operator delete[]"<<endl;
    free(pdead);
}

int Foo::ctorNum = 0;
int Foo::dtorNum = 0;

int main() {
    //auto* p1 = new Foo;
    auto* p2 = new Foo[3];
    cout<<"--------------------"<<endl;
    //auto* p3 = ::new Foo; // 强制采用global new
    //::delete p3;
    delete[] p2;
    //delete p1;
    return 0;
}
