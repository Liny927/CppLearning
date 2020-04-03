/*
 * @Author: Hellcat
 * @Date: 2020-01-27 19:18:10
 * HDU 2571 dp
 */
#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#pragma GCC optimize(2)
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
#define INF 0x3f3f3f3f
typedef long long LL;
typedef unsigned long long ULL;
using namespace std;

int maze[1001][1001];
int dp[1001][1001];
int n, m;

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    mes(maze,0);
    mes(dp,-INF);
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= m; j++)
        scanf("%d", &maze[i][j]);
        dp[1][0] = dp[0][1] = 0;
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= m; j++) {
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        for(int k = 2; k <= j; k++) {
          if(j % k == 0)
            dp[i][j] = max(dp[i][j], dp[i][j / k]);
        }
        dp[i][j] += maze[i][j]; // 当前格子状态加上当前格子幸运值
      }
    cout<<dp[n][m]<<endl;
  }
}