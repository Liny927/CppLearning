/*
 * @Author: Hellcat
 * @Date: 2020-03-10 14:15:14
 */
#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 10;

int n, m, a[N];
struct node {
    int l, r;
    int tmax; // 最大连续子段和
    int lmax; // 最大前缀和
    int rmax; // 最大后缀和
    int sum;  // 区间[l, r]中的最大值
}tr[N<<2];

void pushup(node &u, node &l, node &r) {
    u.sum = l.sum + r.sum;
    u.lmax = max(l.lmax, l.sum + r.lmax);
    u.rmax = max(r.rmax, r.sum + l.rmax);
    u.tmax = max(max(l.tmax, r.tmax), l.rmax + r.lmax);
}

void pushup(int u) {
    pushup(tr[u], tr[u<<1], tr[u<<1 | 1]);
}

void build(int u, int l, int r) {
    tr[u] = {l, r, a[r], a[r], a[r], a[r]};
    if(l == r) return;
    int mid = (l + r) >> 1;
    build(u<<1, l, mid);
    build(u<<1 | 1, mid + 1, r);
    pushup(u);
}

void modify(int u, int x, int v) {
    if(tr[u].l == tr[u].r) { tr[u] = {x, x, v, v, v, v}; return; }
    int mid = (tr[u].l + tr[u].r) >> 1;
    if(x <= mid) modify(u << 1, x, v);
    else modify(u << 1 | 1, x, v);
    pushup(u);
}

node query(int u, int l, int r) {
    if(l <= tr[u].l && tr[u].r <= r) return tr[u];
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
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    build(1, 1, n);
    int p; scanf("%d", &p);
    while(p--) {
        int op, x, y;
        scanf("%d%d%d", &op, &x, &y);
        if(op == 0) modify(1, x, y);
        else {
            node res = query(1, x, y);
            printf("%d\n", res.tmax);
        }
    }
}
