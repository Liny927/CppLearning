/*
 * @Author: Hellcat
 * @Date: 2020-04-03 13:00:33
 */
// 最好不要重载全局 operator new 和 operator delete
// 会和STL库的allocator起冲突
#include <iostream>
#include <cstdlib>
using namespace std;

void* myAlloc(size_t size) {
    if(void* mem = malloc(size))
        return malloc(size);
    else
        throw bad_alloc();
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

inline void operator delete[](void* ptr) noexcept {
    cout<<"ly global delete[]() \n"; myFree(ptr);
}

int main() {
    size_t t = 6;
    int* p = new int;
    delete p;
    int* ptr = new int[10];
    ptr[3] = 3;
    cout<<*(ptr + 3)<<endl; // 3
    delete[] ptr;
}
