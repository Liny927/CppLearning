/*
 * @Author: Hellcat
 * @Date: 2020-02-09 16:47:16
 * O(logn)
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;

int a[maxn];

struct node {
    int l, r;
    ll sum;
    ll lazy;
}tree[maxn*4];

void push_down(int o) {
    if(tree[o].lazy) {
        tree[o*2].lazy += tree[o].lazy;  //左右儿子分别加上父亲的lz
        tree[o*2+1].lazy += tree[o].lazy;
        int mid = (tree[o].l + tree[o].r)/2;
        tree[o*2].sum += tree[o].lazy * (mid - tree[o*2].l + 1);//左右分别求和加起来
        tree[o*2+1].sum += tree[o].lazy * (tree[o*2+1].r - mid);
        tree[o].lazy = 0;//父亲lz归零
    }
    return;
}

void build(int o, int l, int r) {
    tree[o].l = l;
    tree[o].r = r;
    if(l == r) {
        tree[o].sum = a[l];
        return;
    }
    build(o*2, l, (l+r)/2);
    build(o*2+1, (l+r)/2+1, r);
    tree[o].sum = tree[o*2].sum + tree[o*2+1].sum;
    return;
}

ll query(int o, int a, int b) { // 区间查询
    if(tree[o].l >= a && tree[o].r <= b)
        return tree[o].sum;
    int mid = (tree[o].l + tree[o].r)/2;
    ll res = 0;
    if(a <= mid)
        res += query(o*2, a, b);
    if(b > mid)
        res += query(o*2+1, a, b);
    return res;
}

ll sec(int o, int a, int b) {
    if(tree[o].l >= a && tree[o].r <= b)
        return tree[o].sum;
    push_down(o);
    ll res=0;
    if(tree[o*2].r >= a)
        res += sec(o*2, a, b);
    if(tree[o*2+1].l <= b)
        res += sec(o*2+1, a, b);
    return res;
}

void update(int o, int pos, int k) { // 单点修改
    if(tree[o].l == tree[o].r) {
        tree[o].sum += k;
    }
    else {
        if(pos <= (tree[o].l + tree[o].r)/2)
            update(o*2, pos, k);
        else
            update(o*2+1, pos, k);
        tree[o].sum = tree[o*2].sum + tree[o*2+1].sum;
    }
}

void add(int o, int l, int r, int k) {
    if(tree[o].r <= r && tree[o].l >= l) {
        tree[o].sum += k *(tree[o].r - tree[o].l + 1);
        tree[o].lazy += k;
        return;
    }
    push_down(o);
    if(tree[o*2].r >= l)
        add(o*2, l, r, k);
    if(tree[o*2+1].l <= r)
        add(o*2+1, l, r, k);
    tree[o].sum = tree[o*2].sum + tree[o*2+1].sum;
    return;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    build(1, 1, n);
    while(m--) {
        int p, x, y, k;
        scanf("%d", &p);
        if(p == 1) {
            scanf("%d%d%d", &x, &y, &k);
            add(1, x, y, k);
        }
        else {
            scanf("%d%d", &x, &y);
            printf("%lld\n", sec(1, x, y));
        }
    }
}
