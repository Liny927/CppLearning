/*
 * @Author: Hellcat
 * @Date: 2020-02-16 20:34:44
 */
#include <bits/stdc++.h>
using namespace std;

int dp[110][110], root[110][110];

void print(int l, int r) {
    if(l > r) return;
    if(l == r) { printf("%d ", l); return; }
    printf("%d ", root[l][r]);
    print(l, root[l][r] - 1);
    print(root[l][r] + 1, r);
}

int main() {
    int n, x;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &x);
        dp[i][i] = x;
        dp[i][i-1] = 1;
    }
    for(int i = n; i >= 1; i--)
        for(int j = i + 1; j <= n; j++)
            for(int k = i; k <= j; k++) {
                if(dp[i][j] < dp[i][k-1] * dp[k+1][j] + dp[k][k]) {
                    dp[i][j] = dp[i][k-1] * dp[k+1][j] + dp[k][k];
                    root[i][j] = k;
                }
            }
    printf("%d\n", dp[1][n]);
    print(1,n);
}
