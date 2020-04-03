/*
 * @Author: Hellcat
 * @Date: 2020-01-25 21:51:28
 * POJ 1287 networking
 */
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int bin[110], n, m, ans;

struct rec{
    int u, v, w;
    // bool operator < (const rec &a) const {
    //     return w < a.w;
    // }
    bool friend operator < (const rec &a, const rec &b) {
        return a.w < b.w;
    }
}edge[110];


int find(int x) {
    return x == bin[x] ? x : bin[x] =  find(bin[x]);
}

void Kruskal() {
    sort(edge + 1, edge + m + 1);
    for(int i = 1; i <= m; i++) {
        int x = edge[i].u, y = edge[i].v, w = edge[i].w;
        int fx = find(x), fy = find(y);
        if(fx != fy) {
            bin[fx] = fy;
            ans += w;
        }
    }
}

int main() {
    while(~scanf("%d", &n) && n) {
        memset(bin, 0, sizeof(bin));
        ans = 0;
        for(int i = 1;  i <= n; i++) bin[i] = i;
        scanf("%d", &m);
        for(int i = 1; i <= m; i++)
            scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w);
        Kruskal();
        printf("%d\n", ans);
    }
}
