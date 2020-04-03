/*
 * @Author: Hellcat
 * @Date: 2020-01-27 19:39:58
 * HDU 2191 多重背包二进制优化
 */
#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#define IOS ios::sync_with_stdio(false)
#define TIE cin.tie(0)
#define max(x,y) (x>y?x:y)
#define mes(a,b) memset(a,b,sizeof(a))
#define max(x,y) (x>y?x:y)
#define mes(a,b) memset(a,b,sizeof(a))
#define qwq(a,b) for(int i = (a); i < (b); ++i)
#define qeq(a,b) for(int j = (a); j < (b); ++j)
#define qsq(a,b) for(int s = (a); s < (b); ++s)
#define qaq(a,b) for(int k = (a); k > (b); --k)
typedef long long LL;
typedef unsigned long long ULL;
using namespace std;

int main() {
    int T, m, n;
    int p[1010], h[1010], c[1010], dp[1010], v[1010], w[1010];
    int a1, a2, a3;
    scanf("%d", &T);
    while(T--) {
        int dex = 0;
        mes(dp,0);
        scanf("%d%d", &n, &m);
        qwq(0,m) {
            scanf("%d%d%d", &p[i], &h[i], &c[i]); // 价格 重量 袋数
            for(int j = 1; j <= c[i]; j <<= 1) {
                v[dex] = j * p[i];
                w[dex++] = j * h[i];
                c[i] -= j;
            }
            if(c[i] > 0) {
                v[dex] = c[i] * p[i];
                w[dex++] = c[i] * h[i];
            }
        }
            for(int i = 0; i < dex; i++)
                for(int j = n; j >= v[i]; j--)
                    dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        cout<<dp[n]<<endl;
    }
}
