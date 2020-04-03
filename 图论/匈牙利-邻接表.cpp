/*
 * @Author: Hellcat
 * @Date: 2020-03-07 20:40:04
 */
#include <bits/stdc++.h>
using namespace std;

const int N = 1010, M = 1e6 + 10;

bool vis[N];  // 标记第二个集合中的点是否被遍历
/* 邻接表存储所有边, 由于匈牙利算法中只会用到从第一
个集合指向第二个集合的边，所以这里只用存一个方向的边 */
int h[N], e[M], ne[M], idx;
int n, m, k;
int match[N];  // 配对的结果 即存储第二个集合中的每个点当前匹配到第一个集合中的点是哪个

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

bool dfs(int x) {              // 邻接表
    for(int i = h[x]; ~i; i = ne[i]) {
        int j = e[i];
        if(!vis[i]) {
            vis[i] = true;
            if(!match[j] || dfs(match[j])) {
                match[j] = x;
                return true;
            }
        }
    }
    return false;
}

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    memset(h, -1, sizeof(h));
    memset(match, 0, sizeof(match));
    while(k--) {
        int a, b;
        a = read(); b = read();
        if(a > n || b > m || a > m || b > n) continue;
        add(a, b);
    }
    int res = 0;
    for(int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof(vis));
        if(dfs(i)) res++;
    }
    printf("%d\n", res);
}
