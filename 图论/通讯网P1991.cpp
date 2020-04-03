/*
 * @Author: Hellcat
 * @Date: 2020-02-24 20:39:55
 * luogu P1991
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;

int bin[510], n, m, s, p;
int a[510], b[510];
double ans;

struct rec{
    int u, v;
    double w;
    bool operator < (const rec &a) const {
        return w < a.w;
    }
}edge[N];

int find(int x) {
    return x == bin[x] ? x : bin[x] = find(bin[x]);
}

void Kruskal() {
    int cnt = 0;
    sort(edge + 1, edge + m + 1);
    for(int i = 1; i <= m; i++) {
        int fx = find(edge[i].u), fy = find(edge[i].v);
        if(fx != fy) {
            bin[fx] = fy;
            ans = edge[i].w;
            cnt++;
            if(cnt >= p -s) break;
        }
    }
}

int main() {
    scanf("%d%d", &s, &p);
    for(int i = 1; i <= p; i++) {
        scanf("%d%d", &a[i], &b[i]);
        for(int j = 1; j < i; j++) {
            m++;
            edge[m].u = i;
            edge[m].v = j;
            edge[m].w = sqrt((a[i] - a[j]) * (a[i] - a[j]) + (b[i] - b[j]) * (b[i] - b[j]));
        }
    }
    for(int i = 1; i <= p; i++) bin[i] = i;
    Kruskal();
    printf("%.2lf\n", ans);
}
