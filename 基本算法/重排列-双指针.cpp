/*
 * @Author: Hellcat
 * @Date: 2020-02-15 13:05:53
 * 现在有两个长度为 N 的非负整数序列 A 和 B，
 * 问有多少种 A 的重排列满足对于所有的 1≤i≤N，有Ai≤Bi
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f
const int mod = 1e9 + 7;
#pragma GCC optimize(2)

vector<int> a, b;

int main() {
    int n, x;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        a.push_back(x);
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        b.push_back(x);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll res = 1;
    for(int i = 0; i < n; i++) {
        if(a[i] > b[i]) res = 0;
        else {
            int pos = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
                res = res * (i-pos+1) % mod;
        }
    }
    printf("%d\n", res);
}
