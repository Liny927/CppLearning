/*
 * @Author: Hellcat
 * @Date: 2020-03-07 20:40:04
 */
#include <bits/stdc++.h>
using namespace std;

bool vis[1010];
int G[1010][1010];
int match[1010];
int n, m, k;

inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch >'9') {
        if (ch == '-')f = -1;
        ch = getchar();
    }
    while (ch >= '0'&& ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return f * x;
}

bool dfs(int x) { // ÁÚ½Ó¾ØÕó
    for(int i = 1; i <= m; i++) {
        if(!vis[i] && G[x][i]) {
            vis[i] = 1;
            if(!match[i] || dfs(match[i])) {
                match[i] = x;
                return true;
            }
        }
    }
    return false;
}

int main() {
        scanf("%d%d%d", &n, &m, &k);
        memset(G, 0, sizeof(G));
        memset(match, 0, sizeof(match));
        for(int i = 0; i < k; i++) {
            int a, b;
            a = read(); b = read();
            if(a > n || b > m || a > m || b > n) continue;
            G[a][b] = 1;
        }
        int res = 0;
        for(int i = 1; i <= n; i++) {
            memset(vis, 0, sizeof(vis));
            if(dfs(i)) res++;
        }
        printf("%d\n", res);
}
