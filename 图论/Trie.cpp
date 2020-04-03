/*
 * @Author: Hellcat
 * @Date: 2020-03-06 16:28:35
 */
#include <bits/stdc++.h>
using namespace std;

const int  N = 1e5 + 10, M = 3e6;
int a[N], trie[M][2], idx;

void insert(int x) {
    int p = 0;
    for(int i = 31; ~i; i--) { // ~i <=> i >= 0
        int &s  = trie[p][x >> i & 1];
        if(!s) s = ++idx;
        p = s;
    }
}

int query(int x) {
    int res = 0, p = 0;
    for(int i = 31; ~i; i--) {
        int s = x >> i & 1;
        if(trie[p][!s]) {
            res += 1<<i;
            p = trie[p][!s];
        }
        else p = trie[p][s];
    }
    return res;
}

int main() {
    int n; cin>>n;
    for(int i = 0; i < n; i++) { cin>>a[i]; insert(a[i]); }
    int res = 0;
    for(int i = 0; i < n; i++)
        res = max(res, query(a[i]));
    printf("%d\n", res);
}
