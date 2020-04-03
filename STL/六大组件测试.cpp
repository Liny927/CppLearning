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
    // cout<<*v.end()<<endl; Error Ϊ"ǰ�պ�"����
    for(auto it = v.begin(); it != v.end(); it++) // iteratorʵ����Ϊ������ָ��
        cout<<*it<<endl;
    cout<<count_if(v.begin(), v.end(), // iterator
        not1(bind2nd(less<int> (), 70)))<<endl; // ���ڵ���70
    // bind2nd��(C++11 ������) (C++17 ���Ƴ�)
    // lambda���ʽ
    cout<<count_if(v.begin(), v.end(),
        [](int i) { return i % 3 == 0; })<<endl;
    return 0;
}
