/*
 * @Author: Hellcat
 * @Date: 2020-02-10 11:22:44
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 1e5 + 10;

string s, a;

int main() {
    cin>>s;
    a = s;
    for(int i = 1; i < s.length(); i++) {
        if(s.substr(i) > a) a = s.substr(i);
    }
    cout<<a<<endl;
}