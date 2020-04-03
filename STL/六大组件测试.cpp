/*
 * @Author: Hellcat
 * @Date: 2020-03-31 10:50:39
 */
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

int main() {
    int a[6] = { 11, 26, 46, 54, 77, 89 };
    vector<int, allocator<int> > v(a, a + 6);
    // cout<<*v.end()<<endl; Error 为"前闭后开"区间
    for(auto it = v.begin(); it != v.end(); it++) // iterator实质上为泛化的指针
        cout<<*it<<endl;
    cout<<count_if(v.begin(), v.end(), // iterator
        not1(bind2nd(less<int> (), 70)))<<endl; // 大于等于70
    // bind2nd在(C++11 中弃用) (C++17 中移除)
    // lambda表达式
    cout<<count_if(v.begin(), v.end(),
        [](int i) { return i % 3 == 0; })<<endl;
    return 0;
}
