/*
 * @Author: Hellcat
 * @Date: 2020-02-10 22:46:53
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 10;

int C[maxn], a[maxn];
int n, m;

inline int lowbit(int x) {
    return x&-x;
}

ll sum(int x) {
    ll res = 0;
    while(x) {
        res += C[x];
        x -= lowbit(x);
    }
    return res;
}

void add(int x, ll v) {
    while(x <= n) {
        C[x] += v;
        x += lowbit(x);
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]), add(i, a[i]);
    int opt, x, y;
    while(m--) {
        scanf("%d%d%d", &opt, &x, &y);
        if(opt == 1) add(x,y);
        else {
            ll ans = sum(y) - sum(x-1);
            printf("%lld\n", ans);
        }
    }
}
