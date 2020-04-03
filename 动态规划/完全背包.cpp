/*
 * @Author: Hellcat
 * @Date: 2020-01-26 12:45:44
 * luogu P2722
 */
#include <bits/stdc++.h>
#define qwq(a,b) for(int i = a; i < b; i++)
#define qeq(a,b) for(int j = a; j < b; j++)
#define mes(a,b) memset(a,0,sizeof(a))
typedef long long LL;
using namespace std;

int n, m;
const int maxn = 15010;
int w[maxn], v[maxn];
int dp[maxn];

int main() {
    scanf("%d%d", &m, &n);
    qwq(0,n) scanf("%d%d", &v[i], &w[i]);
    mes(dp,0);
    for(int i = 0; i < n; i++)
        for(int j = w[i]; j <= m; j++)
            dp[j] = max(dp[j], dp[j-w[i]] + v[i]);
    printf("%d\n", dp[m]);
}
