/*
 * @Author: Hellcat
 * @Date: 2020-04-03 13:00:33
 */
#include <iostream>
using namespace std;

void* myAlloc(size_t size) {
    return malloc(size);
}

void myFree(void* ptr) {
    return free(ptr);
}

inline void* operator new(size_t size) {
    cout<<"ly global new() \n"; return myAlloc(size);
}

inline void* operator new[](size_t size) {
    cout<<"ly global new[]() \n"; return myAlloc(size);
}

inline void operator delete(void* ptr) {
    cout<<"ly global delete() \n"; return myFree(ptr);
}

inline void operator delete[](void* ptr) {
    cout<<"ly global delete() \n"; myFree(ptr);
}

int main() {
    size_t t = 6;
    int* p = new int;
}