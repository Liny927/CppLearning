/*
 * @Author: Hellcat
 * @Date: 2020-03-30 20:57:36
 */
// ranged-base for(since c++11)
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<double> vec { 3.132, 321.3, 3123.2 };
    for(double i : vec)
        cout<<i<<' ';
    puts("");
    for(auto& elem : vec) // pass by reference
        elem *= 3;
    for(auto i : vec)
        cout<<i<<' ';
    puts("");
    for(int i : {2, 3, 44, 53, 5, 6, 7} ) {
        cout<<i<<' ';
    }
}
