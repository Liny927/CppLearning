/*
 * @Author: Hellcat
 * @Date: 2020-03-08 21:16:28
 */
#include <bits/stdc++.h>
using namespace std;

const int N = 3e6 + 10;

int n;
int stk[N], a[N], tt, re[N];

inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while (ch <'0' || ch >'9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0'&& ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return f * x;
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) a[i] = read();
    for(int i = n; i >= 1; i--) {
        while(a[i] >= a[stk[tt]] && tt) tt--;
        re[i] = stk[tt];
        stk[++tt] = i;
    }
    for(int i = 1; i <= n; i++)
        printf("%d ", re[i]);
}
