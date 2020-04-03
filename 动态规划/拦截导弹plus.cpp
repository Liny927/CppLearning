/*
 * @Author: Hellcat
 * @Date: 2020-03-05 19:20:16
 * POJ 3700
 */
#include <bits/stdc++.h>
using namespace std;

const int N = 55;

int n, ans;
int q[N], up[N], down[N];

void dfs(int u, int su, int sd) {
    if(su + sd >= ans) return;
    if(u == n) {
        ans = su + sd;
        return;
    }
    // 将当前数放到上升子序列
    int k = 0;
    while(k < su && up[k] >= q[u]) k++;
    int t = up[k];
    up[k] = q[u];
    if(k < su) dfs(u + 1, su, sd);
    else dfs(u + 1, su + 1, sd);
    up[k] = t;
    // 将当前数放到下降子序列
    k = 0;
    while(k < sd && down[k] <= q[u]) k++;
    t = down[k];
    down[k] = q[u];
    if(k < sd) dfs(u + 1, su, sd);
    else dfs(u + 1, su, sd + 1);
    down[k] = t;
}

int main() {
    while(~scanf("%d", &n) && n) {
        for(int i = 0; i < n; i++)
            scanf("%d", &q[i]);
        ans = n;
        dfs(0, 0, 0);
        printf("%d\n", ans);
    }
}
