/*
 * @Author: Hellcat
 * @Date: 2019-12-23 20:01:34
 * HDU 1010 dfs + 奇偶性剪枝
 */

#pragma GCC optime(2)
#include <iostream>
#include <string.h>
#include <string>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#include <ctype.h>
#include <algorithm>
#define max(x,y) (x>y?x:y)
#define mes(a,b) memset(a,b,sizeof(a))
#define max(x,y) (x>y?x:y)
#define mes(a,b) memset(a,b,sizeof(a))
#define qwq(a,b) for(int i = (a); i < (b); ++i)
#define qeq(a,b) for(int j = (a); j < (b); ++j)
#define qaq(a,b) for(int k = (a); k > (b); --k)
typedef long long LL;
typedef unsigned long long ULL;
using namespace std;

char maps[10][10];
int n, m, t;
bool escape;
int si, sj; //the start point
int di, dj; //the door point
int to[4][2] = {
    {0, -1}, {0, 1}, {1, 0}, {-1, 0}
};

void dfs(int si, int sj, int cnt) {
    int temp;
    //不满足搜索条件
    if(si > n || sj > m || si <= 0 || sj <= 0) return ;
    //到达门
    if(cnt == t && si == di && sj == dj) escape = 1;
    if(escape) return;
    //奇偶性剪枝 剩余步数必须是偶数 (奇 - 奇 = 偶 || 偶 - 偶 = 偶)
    temp = (t - cnt) - abs(si - di) - abs(sj - dj);
    if(temp < 0 || temp & 1) return ;
    for(int i = 0; i < 4; i++) {   //尝试四个方向
        int nx = si + to[i][0];
        int ny = sj + to[i][1];
        if(maps[nx][ny] != 'X') {
            maps[nx][ny] = 'X';
            dfs(nx, ny, cnt + 1);
            maps[nx][ny] = '.';   //回溯法
        }
    }
    return;
}

int main()
{
    int i,j,si,sj;
    while(cin>>n>>m>>t)
    {
      if(n==0&&m==0&&t==0) break;
      int wall=0;
      for(i=1;i<=n;i++)
         for(j=1;j<=m;j++)
         {
            cin>>maps[i][j];
            if(maps[i][j]=='S') { si=i; sj=j; }
            else if(maps[i][j]=='D') { di=i; dj=j; }
            else if(maps[i][j]=='X') wall++;
         }
       if(n*m-wall<=t)
       {
           cout<<"NO"<<endl;
           continue;
       }
       escape=0;
       maps[si][sj]='X';
       dfs(si,sj,0);
       if(escape) cout<<"YES"<<endl;
       else cout<<"NO"<<endl;
   }
   return 0;
}