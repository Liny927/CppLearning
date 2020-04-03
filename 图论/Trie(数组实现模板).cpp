/*
 * @Author: Hellcat
 * @Date: 2020-03-06 15:10:13
 */
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int trie[N][26], cnt[N], idx;    // idx为当前新分配的存储位置
char str[55];

void insert(char *str) {
    int p = 0;
    for(int i = 0; str[i]; i++) {
        int u = str[i] - 'a';
        if(!trie[p][u]) trie[p][u] = ++idx;  // 如果对应字符还没有值
        p = trie[p][u];
    }
    cnt[p]++;
}

int query(char *str) {      // 返回以某个字符串为前缀的单词的数量
    int p = 0;
    for(int i = 0; str[i]; i++) {
        int u = str[i] - 'a';
        if(!trie[p][u]) return 0;
        p = trie[p][u];
    }
    return cnt[p];
}
