/*
 * @Author: Hellcat
 * @Date: 2020-03-10 23:02:08
 * Interval GCD
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e5 + 10;
int n, m;

ll a[N];

struct node {
    int l, r;
    ll sum, d;  // 维护总和 最大公约数
}tr[N << 2];

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

void pushup(node &u, node &l, node &r) {
    u.sum = l.sum + r.sum;
    u.d = gcd(l.d, r.d);
}

void pushup(int u) {
    pushup(tr[u], tr[u<<1], tr[u<<1 | 1]);
}

void build(int u, int l, int r) {
    ll b = a[r] - a[r-1]; // 差分
    tr[u] = {l, r, b, b};
    if(l == r) return;
    int mid = (l + r) >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

void modify(int u, int x, ll v) {
    if(tr[u].l == tr[u].r) { ll b = tr[u].sum + v; tr[u] = {x, x, b, b}; return; }
    int mid = (tr[u].l + tr[u].r) >> 1;
    if(x <= mid) modify(u << 1, x, v);
    else modify(u<<1 | 1, x, v);
    pushup(u);
}

node query(int u, int l, int r) {
    //printf("%d %d %d\n", u, l, r);
    if(l <= tr[u].l && tr[u].r <= r)  return tr[u];
    int mid = (tr[u].l + tr[u].r) >> 1;
    if(r <= mid) return query(u << 1, l, r);
    if(l > mid) return query(u << 1 | 1, l, r);
    auto left = query(u << 1, l, r);
    auto right = query(u << 1 | 1, l, r);
    node res;
    pushup(res, left, right);
    return res;
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    build(1, 1, n);
    while(m--) {
        char op[2];
        int l, r; ll d;
        scanf("%s%d%d", op, &l, &r);
        if(*op == 'Q') {
            auto left = query(1, 1, l), right = query(1, l + 1, r);
            printf("%lld\n", abs(gcd(left.sum, right.d)));
        }
        else {
            scanf("%lld", &d);
            modify(1, l, d);
            if(r + 1 <= n) modify(1, r + 1, -d);
        }
    }
}
