/*
 * @Author: Hellcat
 * @Date: 2020-03-16 20:37:52
 */
#include <bits/stdc++.h>
using namespace std;

int bin[210], n, m, res;

struct rec{
    int u, v, w;
    bool operator < (const rec &a) const{
        return w  < a.w;
    }
}edge[210];

int find(int x) {
    return x == bin[x] ? x : bin[x] = find(bin[x]);
}

void Kruskal() {
    sort(edge, edge + m);
    for(int i = 0; i < m; i++) {
        int fx = find(edge[i].u), fy = find(edge[i].v), w = edge[i].w;
        if(fx != fy) {
            bin[fx] = fy;
        }
        else {
            res += w;
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) bin[i] = i;
    for(int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w);
    }
    Kruskal();
    printf("%d\n", res);
}
