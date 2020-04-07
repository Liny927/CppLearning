/*
 * @Author: Hellcat
 * @Date: 2020-04-03 16:10:54
 */
#include <bits/stdc++.h>
using namespace std;

int test() {
    set<int> S {9, 134, 43, 43, 3, 13}; // 以less<>为排序准则
    multiset<int> c {9, 134, 134, 43, 43, 3, 13};
    set<int, greater<>> Set {3, 5, 6, 7, 8, 8};
    cout<<Set.size()<<endl;
//    for(auto it = Set.begin(); it != Set.end(); it++)
//        if(*it == 8) *it = 9; 丛迭代器的角度看Set元素是常量
    for(auto it = S.begin(); it != S.end(); it++)
        cout<<*it<<endl;
    for(auto it = Set.begin(); it != Set.end(); it++)
        cout<<*it<<endl;
    cout<<S.count(134)<<endl;
    cout<<c.count(134)<<endl;
}
