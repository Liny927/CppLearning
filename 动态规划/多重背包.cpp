/*
 * @Author: Hellcat
 * @Date: 2020-01-27 19:00:30
 * HDU 2191 多重背包转化为01背包
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
    int p[1010], h[1010], c[1010], dp[1010];
    scanf("%d", &T);
    while(T--) {
        mes(dp,0);
        scanf("%d%d", &n, &m);
        qwq(0,m) {
            scanf("%d%d%d", &p[i], &h[i], &c[i]); // 价格 重量 袋数
        }
        for(int q = 0; q < m; q++)
            for(int i = 1; i <= c[q]; i++)
                for(int j = n; j >= p[q]; j--)
                    dp[j] = max(dp[j], dp[j-p[q]] + h[q]);
        cout<<dp[n]<<endl;
    }
}
