/*
 * @Author: Hellcat
 * @Date: 2020-02-01 16:09:55
 * HDU 1686 KMP
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 10;

char p[N], s[N];
int ne[N];

int main() {
    cin>>s + 1>>p + 1;
    int n = strlen(s + 1), m = strlen(p + 1);
    // 求next的过程
    for(int i = 2, j = 0; i <= m; i++) {
        while(j && p[i] != p[j + 1]) j = ne[j];
        if(p[i] == p[j + 1]) j++;
        ne[i] = j;
    }
    // kmp匹配过程
    for(int i = 1, j = 0; i <= n; i++) {
        while(j && (j == n || s[i] != p[j + 1])) j = ne[j];
        if(s[i] == p[j + 1]) j++;
        if(j == m) {
            printf("%d\n", i - m + 1);
            j = ne[j];
        }
    }
    for(int i = 1; i <= m; i++)
        printf("%d ", ne[i]);
}
