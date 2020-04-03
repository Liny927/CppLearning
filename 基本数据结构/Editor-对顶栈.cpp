/*
 * @Author: Hellcat
 * @Date: 2020-02-27 20:19:10
 */
#include <bits/stdc++.h>
using namespace std;

const int N = 1e8 + 10;

int stkl[N], stkr[N], tl, tr;
int s[N], f[N]; // s维护当前前缀和 f维护当前最大前缀和
char str[10];

void push_left(int x) {
    stkl[++tl] = x;
    s[tl] = s[tl-1] + x;
    f[tl] = max(f[tl-1], s[tl]);
}

int main() {
    int n;
    while(~scanf("%d", &n)) {
        f[0] = INT_MIN;
        tl = tr = 0;
        s[0] = 0;
        while(n--) {
            scanf("%s", str);
            int x;
            if(*str == 'I') {
                scanf("%d", &x);
                push_left(x);
            }
            if(*str == 'D') {
                if(tl > 0) tl--;
            }
            if(*str == 'L') {
                if(tl > 0) stkr[++tr] = stkl[tl--];
            }
            if(*str == 'R') {
                if(tr > 0) push_left(stkr[tr--]);
            }
            if(*str == 'Q') {
                scanf("%d", &x);
                printf("%d\n", f[x]);
            }
        }
    }
}