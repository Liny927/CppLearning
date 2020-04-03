/*
 * @Author: Hellcat
 * @Date: 2020-03-13 11:47:30
 * POJ3468
 */
#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10;

int n, m;
int a[N];
ll tr1[N];  // 维护b[i]的前缀和
ll tr2[N];  // 维护i * b[i]的前缀和

int lowbit(int x) {
    return x & -x;
}

void add(ll *tr, int x, ll v){
    for(int i = x; i <= n; i += lowbit(i)) tr[i] += v;
}

ll sum(ll *tr, int x) {
    ll res = 0;
    for(int i = x; i; i -= lowbit(i)) res += tr[i];
    return res;
}

ll prefix_sum(int x) {
    return sum(tr1, x) * (x + 1) - sum(tr2, x);
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]), add(tr1, i, a[i] - a[i-1]), add(tr2, i, 1ll * i * (a[i] - a[i-1]));
    while(m--) {
        char op[2]; int l, r, d;
        scanf("%s%d%d", op, &l, &r);
        if(*op == 'Q') {
            printf("%lld\n", prefix_sum(r) - prefix_sum(l - 1));
        }
        else {
            scanf("%d", &d);
            // a[l] += d;
            add(tr1, l, d), add(tr2, l, l * d);
            // a[r + 1] -= d;
            add(tr1, r + 1, -d), add(tr2, r + 1, (r + 1) * -d);
        }
    }
}
