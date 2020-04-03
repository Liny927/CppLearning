/*
 * @Author: Hellcat
 * @Date: 2020-03-17 13:59:35
 */
#include <bits/stdc++.h>
using namespace std;

const int N = 1010, M = N * N, K = 2 * N * N;

int n, m, cnt, res;
int ids[N][N];     // 将二维坐标转化为一维
int bin[M];

struct rec{
    int u, v, w;
}edge[K];

int find(int x) {
    return x == bin[x] ? x : bin[x] = find(bin[x]);
}

void get_edge() {
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1}, dw[4] = {1, 2, 1, 2};
    for(int z = 0; z < 2; z++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                for(int u = 0; u < 4; u++)
                    if(u % 2 == z) {       // 设计u z达到先枚举上下再枚举左右的效果
                        int nx = i + dx[u], ny = j + dy[u], w = dw[u];
                        if(nx && nx <= n && ny && ny <= m) {
                            int a = ids[i][j], b = ids[nx][ny];
                            if(a < b) edge[cnt++] = {a, b, w};
                        }
                    }
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n * m; i++)
        bin[i] = i;
    // 初始化ids数组 二维->一维
    for(int i = 1, t = 1; i <= n; i++)
        for(int j = 1; j <= m; j++, t++)
            ids[i][j] = t;
    int x1, y1, x2, y2;
    while(~scanf("%d%d%d%d", &x1, &y1, &x2, &y2)) {
        int a = ids[x1][y1], b = ids[x2][y2];
        // 建边(已有连线)
        bin[find(a)] = b;
    }
    get_edge();
    for(int i = 0; i < cnt; i++) {
        int fx = find(edge[i].u), fy = find(edge[i].v), w = edge[i].w;
        if(fx != fy) {
            bin[fx] = fy;
            res += w;
        }
    }
    printf("%d\n", res);
}