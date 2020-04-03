/*
 * @Author: Hellcat
 * @Date: 2020-02-01 14:26:09
 * HDU 1233 最小生成树 kruskal
 */
#include <bits/stdc++.h>
#pragma GCC optimize(2)
#define IOS ios::sync_with_stdio(false)
#define TIE cin.tie(0)
#define max(x,y) (x>y?x:y)
#define mes(a,b) memset(a,b,sizeof(a))
#define qwq(a,b) for(int i = (a); i < (b); ++i)
#define qeq(a,b) for(int j = (a); j < (b); ++j)
#define qsq(a,b) for(int s = (a); s < (b); ++s)
#define qaq(a,b) for(int k = (a); k > (b); --k)
#define INF 0x3f3f3f3f
using namespace std;

const int maxn = 1e4 + 10;

int bin[maxn];
int n, m;

int find(int x) {
    return bin[x] == x ? x : bin[x] = find(bin[x]);
}

// int merge(int x, int y) {
//     int fx = find(x);
//     int fy = find(y);
//     if(fx != fy) {
//         bin[fx] = fy;
//     }
// }

struct node{
    int a;
    int b;
    int dis;
}p[maxn];

bool cmp(node a, node b) {
    return a.dis < b.dis;
}

int kruskal() {
    int ans = 0;
    qwq(0,n + 1) bin[i] = i;
    sort(p + 1, p + m + 1, cmp);
    for(int i = 1; i <= m; i++) {
        int fx = find(p[i].a);
        int fy = find(p[i].b);
        if(fx == fy) continue;
        bin[fy] = fx;
        ans += p[i].dis;
    }
    return ans;
}

int main() {
    while(~scanf("%d", &n) && n) {
        m = n * (n - 1) / 2;
        for(int i = 1; i <= m; i++) {
            scanf("%d%d%d", &p[i].a, &p[i].b, &p[i].dis);
        }
        printf("%d\n", kruskal());
    }
}
