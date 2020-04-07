/*
 * @Author: Hellcat
 * @Date: 2020-04-05 10:40:09
 */
#include <iostream>
#include <cstring>
using namespace std;

int test01() {
    // lambda表达式可以当做inline函数来使用
    [] {
        cout<<"hello lambda"<<endl;
    }();

    auto l = [] {
        cout<<"lambda!"<<endl;
    };
    l();

    auto la = [] (const string& s) {
        cout<<s<<endl;
    };
    la("lambda!!");
}
