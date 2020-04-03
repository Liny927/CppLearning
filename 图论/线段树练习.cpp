/*
 * @Author: Hellcat
 * @Date: 2020-03-11 15:14:58
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10;

int n, a[N];
vector<double> y_s;

struct segment {
    double x, y1, y2;
    int k;
    bool operator < (const segment &t) const {
        return x < t.x;
    }
}seg[N << 1];

struct node {
    int l, r;
    int cnt;
    double len;
}tr[N << 3];

int find(double y) {
    return lower_bound(y_s.begin(), y_s.end(), y) - y_s.begin();
}

void pushup(int u) {
    if(tr[u].cnt) tr[u].len = y_s[tr[u].r + 1] - y_s[tr[u].l];
    else if (tr[u].l != tr[u].r)
    {
        tr[u].len = tr[u<<1].len + tr[u<<1 | 1].len;
    }
    else tr[u].len = 0;
}

void build(int u, int l, int r) {
    tr[u] = {l, r, 0, 0};
    if(l == r) return;
    int mid = (tr[u].l + tr[u].r) >> 1;
    build(u<<1, l, mid), build(u<<1 | 1, mid + 1, r);
}

void modify(int u, int l, int r, int k) {
    if(l <= tr[u].l && tr[u].r <= r) {
        tr[u].cnt += k;
        pushup(u);
        return;
    }
    int mid = (tr[u].l + tr[u].r) >> 1;
    if(l <= mid) modify(u << 1, l, r, k);
    if(r > mid) modify(u << 1 | 1, l, r, k);
    pushup(u);
}

int main() {
    int T = 1;
    while(~scanf("%d", &n), n) {
        y_s.clear();
        for(int i = 0, j = 0; i < n; i++) {
            double x1, x2, y1, y2;
            scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
            seg[j++] = {x1, y1, y2, 1};
            seg[j++] = {x2, y1, y2, -1};
            y_s.push_back(y1), y_s.push_back(y2);
        }
        sort(y_s.begin(), y_s.end());
        y_s.erase(unique(y_s.begin(), y_s.end()), y_s.end());
        build(1, 0, y_s.size() - 2);
        sort(seg, seg + 2*n);
        double res = 0;
        for(int i = 0; i < 2 * n; i++) {
            if(i > 0) res += tr[1].len * (seg[i].x - seg[i-1].x);
            modify(1, find(seg[i].y1), find(seg[i].y2) - 1, seg[i].k);
        }
        printf("Test case #%d\n", T++);
        printf("Total explored area: %.2f\n", res);
        puts("");
    }
}
