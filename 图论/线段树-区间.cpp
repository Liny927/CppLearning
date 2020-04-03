/*
 * @Author: Hellcat
 * @Date: 2020-03-10 23:02:08
 */

// pushdown 函数需要在递归之前(modify query) pushup函数放在值被修改(新建)之后(build modify)

#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10;

int n, m, a[N];

struct node {
    int l, r;
    ll sum, add;
}tr[N << 2];

void pushup(int u) {
    tr[u].sum = tr[u<<1].sum + tr[u<<1 | 1].sum;
}

void pushdown(int u) {
    //auto &root = tr[u], &left = tr[u<<1], &right = tr[u<<1 | 1];
    if(tr[u].add) {
        tr[u<<1].add += tr[u].add, tr[u<<1].sum += 1ll * (tr[u<<1].r - tr[u<<1].l + 1) * tr[u].add;
        tr[u<<1 | 1].add += tr[u].add, tr[u<<1 | 1].sum += 1ll * (tr[u<<1 | 1].r - tr[u<<1 | 1].l + 1) * tr[u].add;
        tr[u].add = 0;
    }
}

void build(int u, int l, int r) {
    tr[u] = {l, r, a[r], 0};
    if(l == r) return;
    int mid = (l + r) >> 1;
    build(u<<1, l, mid), build(u<<1 | 1, mid + 1, r);
    pushup(u);
}

void modify(int u, int l, int r, int v) { // 区间修改 Interval
    if(l <= tr[u].l && tr[u].r <= r) {
        tr[u].sum += 1ll * (tr[u].r - tr[u].l + 1) * v;
        tr[u].add += v;
        return;
    }
    pushdown(u);
    int mid = (tr[u].l + tr[u].r) >> 1;
    if(l <= mid) modify(u << 1, l, r, v);
    if(r > mid) modify(u << 1 | 1, l, r, v);
    pushup(u);
}

ll query(int u, int l, int r) {
    if( l <= tr[u].l && tr[u].r <= r) return tr[u].sum;
    pushdown(u);
    int mid = (tr[u].l + tr[u].r) >> 1;
    ll sum = 0;
    if(l <= mid) sum += query(u << 1, l, r);
    if(r > mid) sum += query(u<<1 | 1, l, r);
    return sum;
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    build(1, 1, n);
    while(m--) {
        char op[2]; int l, r, d;
        scanf("%s%d%d", op, &l, &r);
        if(*op == '2') { printf("%lld\n", query(1, l, r)); }
        else {
            scanf("%d", &d);
            modify(1, l, r, d);
        }
    }
}
