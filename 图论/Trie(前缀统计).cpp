/*
 * @Author: Hellcat
 * @Date: 2020-03-06 16:17:57
 */
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10, M = 5e5;

int n, m;
int trie[M][26], cnt[N], idx;
char str[N];

void insert(char *str) {
    int p = 0;
    for(int i = 0; str[i]; i++) {
        int &s = trie[p][str[i] - 'a'];
        if(!s) s = ++idx;
        p = s;
    }
    cnt[p]++;
}

int query(char *str) {
    int p = 0, res = 0;
    for(int i = 0; str[i]; i++) {
        int &s = trie[p][str[i] - 'a'];
        if(!s) break;
        p = s;
        res += cnt[p];
    }
    return res;
}

int main() {
    cin>>n>>m;
    while(n--) {
        cin>>str;
        insert(str);
    }
    while(m--) {
        cin>>str;
        cout<<query(str)<<endl;
    }
}
