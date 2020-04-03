/*
 * @Author: Hellcat
 * @Date: 2020-03-08 17:36:42
 */
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10, M = 2 * N;

int n, ans = 0x3f;
int h[N], e[M], ne[M], idx;
bool vis[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

// 返回以u为根的子树中点的数量
int dfs(int u) {
    vis[u] = true;
    int sum = 1, res = 0;
    for(int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if(!vis[j]) {
            int s = dfs(j);
            res = max(res, s);
            sum += s;
        }
    }
    res = max(res, n - sum);
    ans = min(ans, res);
    return sum;
}

int main() {
    scanf("%d", &n);
    memset(h, -1, sizeof(h));
    for(int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b), add(b, a);
    }
    dfs(1);
    printf("%d\n", ans);
}
