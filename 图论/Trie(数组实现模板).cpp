/*
 * @Author: Hellcat
 * @Date: 2020-03-06 15:10:13
 */
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int trie[N][26], cnt[N], idx;    // idxΪ��ǰ�·���Ĵ洢λ��
char str[55];

void insert(char *str) {
    int p = 0;
    for(int i = 0; str[i]; i++) {
        int u = str[i] - 'a';
        if(!trie[p][u]) trie[p][u] = ++idx;  // �����Ӧ�ַ���û��ֵ
        p = trie[p][u];
    }
    cnt[p]++;
}

int query(char *str) {      // ������ĳ���ַ���Ϊǰ׺�ĵ��ʵ�����
    int p = 0;
    for(int i = 0; str[i]; i++) {
        int u = str[i] - 'a';
        if(!trie[p][u]) return 0;
        p = trie[p][u];
    }
    return cnt[p];
}
