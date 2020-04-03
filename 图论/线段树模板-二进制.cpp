/*
 * @Author: Hellcat
 * @Date: 2020-03-09 22:45:40
 * luogu P1198
 */
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int m, p;
struct node {
    int l, r;
    int v;  // 区间[l, r]中的最大值
}tr[N<<2];

void pushup(int u) { // 由子节点信息计算父节点信息(从下往上更新)
    tr[u].v = max(tr[u<<1].v, tr[u<<1 | 1].v);
}

void build(int u, int l, int r) {
    tr[u] = {l, r};
    if(l == r) return;
    int mid = (l + r) >> 1;
    build(u<<1, l, mid),build(u<<1 | 1, mid + 1, r);
    pushup(u);
}

int query(int u, int l, int r) {
    if(l <= tr[u].l && tr[u].r <= r) return tr[u].v;  // 树中节点已经被完全包含在[l, r]中
    int mid = (tr[u].l + tr[u].r) >> 1;
    int val = -0x3f;
    if(l <= mid) val = max(val, query(u<<1, l, r));
    if(r > mid) val = max(val, query(u<<1 | 1, l, r));
    return val;
}

void modify(int u, int x, int v) {
    if(tr[u].l == tr[u].r) { tr[u].v = v; return; } // 找到叶节点
    int mid = (tr[u].l + tr[u].r) >> 1;
    if(x <= mid) modify(u<<1, x, v);
    else modify(u<<1 | 1, x, v);
    pushup(u);
}
int main() {
    int n = 0, last = 0;
    scanf("%d%d", &m, &p);
    build(1, 1, m);
    while(m--) {
        int x;
        char op[2];
        scanf("%s%d", op, &x);
        if(*op == 'Q') {
            last = query(1, n - x + 1, n);
            printf("%d\n", last);
        }
        else {
            modify(1, n + 1, (last + x) % p);
            n++;
        }
    }
}
