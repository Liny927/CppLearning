/*
 * @Author: Hellcat
 * @Date: 2020-01-25 15:37:41
 * P1141 01迷宫 bfs
 */
#include <bits/stdc++.h>
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

typedef pair<int,int> P;
char maze[1001][1001];
bool vis[1001][1001];
int block[1001][1001];  // 记录从位置(i,j)出发可达的格子数量
int to[4][2] = {
    {0, -1}, {0, 1}, {1, 0}, {-1, 0}
};
int n, m;
int x, y, ans;

void bfs() {
    vector<P> pos; // 记录连通块内格子坐标
    queue<P> que;
    que.push(P(x,y));
    vis[x][y] = 1;
    ans = 1;
    while(que.size()) {
        P p = que.front(); que.pop();
        pos.push_back(p);
        qwq(0,4) {
            int nx = p.first + to[i][0], ny = p.second + to[i][1];
            if(!maze[nx][ny] || vis[nx][ny] || maze[p.first][p.second] == maze[nx][ny]) continue;
            que.push(P(nx,ny));
            vis[nx][ny] = 1;
            ans++;
        }
    }
    for(auto v : pos) block[v.first][v.second] = ans;
}

int main() {
    mes(maze,'\0');
    mes(vis,0);
    mes(block,0);
    scanf("%d%d", &n, &m);
    qwq(1,n + 1) {
        scanf("%s", maze[i] + 1);
    }
    qwq(0,m) {
        scanf("%d%d", &x, &y);
        if(!block[x][y]) bfs();
        printf("%d\n", block[x][y]);
    }
}
