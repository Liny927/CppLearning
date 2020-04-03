/*
 * @Author: Hellcat
 * @Date: 2020-01-22 14:05:27
 * luogu P1443 bfs
 */
#include <iostream>
#include <string.h>
#include <string>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <ctype.h>
#include <algorithm>
#define IOS ios::sync_with_stdio(false)
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

int n, m;
int si, sj;
int res[401][401];
int vis[401][401];
int to[8][2] = {{1,2}, {2,1}, {2,-1}, {1,-2}, {-1,-2}, {-2,-1}, {-2,1}, {-1,2}};
typedef pair<int,int> P;

void bfs() {
    queue<P> que;
    que.push(P(si,sj));
    vis[si][sj] = 1;
    res[si][sj] = 0;
    while(que.size()) {
        P p = que.front();
        que.pop();
        qwq(0,8) {
            int nx = p.first + to[i][0], ny = p.second + to[i][1];
            if(1 <= nx && nx <= n && 1 <= ny && ny <= m && !vis[nx][ny]) {
                que.push(P(nx,ny));
                vis[nx][ny] = 1;
                res[nx][ny] = res[p.first][p.second] + 1;
            }
        }
    }
}

int main() {
    mes(res,-1);
    mes(vis,0);
    cin>>n>>m>>si>>sj;
    bfs();
    qwq(1,n+1){
        qeq(1,m+1) {
            printf("%-5d",res[i][j]);
        }
        cout<<endl;
    }
}