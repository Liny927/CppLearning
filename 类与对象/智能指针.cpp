/*
 * @Author: Hellcat
 * @Date: 2020-03-29 17:49:49
 * pointer-like classes
 */
#include <iostream>
using namespace std;

template <class T>
class shared_ptr {
public:
    T& operator* () const { return *px; }
    T* operator-> () const { return px; }
    shared_ptr(T* p) : px(p) {}
private:
    T* px;
    long* pn;
};
