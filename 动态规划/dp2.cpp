/*
 * @Author: Hellcat
 * @Date: 2020-01-26 12:45:44
 * luogu P1164
 */
#include <bits/stdc++.h>
#define qwq(a,b) for(int i = a; i < b; i++)
#define qeq(a,b) for(int j = a; j < b; j++)
#define mes(a,b) memset(a,0,sizeof(a))
typedef long long LL;
using namespace std;

const int maxn = 100010;
int w[maxn];
int dp[maxn];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    qwq(0,n) scanf("%d", &w[i]);
    mes(dp,0);
    dp[0] = 1;  // 花完所有钱有1种方案
    for(int i = 0; i < n; i++)
        for(int j = m; j >= w[i]; j--)
            dp[j] = dp[j] + dp[j-w[i]];
    cout<<dp[m]<<endl;
}
