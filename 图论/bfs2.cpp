/*
 * @Author: Hellcat
 * @Date: 2020-01-20 23:43:55
 * POJ2251 三维迷宫求最短路 bfs
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

char maze[31][31][31];
bool vis[31][31][31];
int to[6][3] = {{0, 0, 1}, {0, 0, -1}, {1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}};
int pile, len, wid;
int sp, sl, sw; //the start point
int ep, el, ew; //the exit point

struct node {
    int p, l, w;  //记录坐标
    int cnt;      //记录步数
    node(int p, int l, int w, int cnt) : p(p), l(l), w(w), cnt(cnt) {} //构造函数
};

bool bfs() {
    queue<node> q;
    vis[sp][sl][sw] = 1;
    q.push(node(sp,sl,sw,0));
    while(!q.empty()) {
        node tmp = q.front();
        q.pop();
        if(tmp.p == ep && tmp.l == el && tmp.w == ew) {
            printf("Escaped in %d minute(s).\n",tmp.cnt);
            return true;
        }
        qwq(0,6) {
            int np = tmp.p + to[i][0];
            int nl = tmp.l + to[i][1];
            int nw = tmp.w + to[i][2];
            if(1 <= np && np <= pile && 1 <= nl && nl <= len && 1 <= nw && nw <= wid && !vis[np][nl][nw] && maze[np][nl][nw] != '#') {
                q.push(node(np,nl,nw,tmp.cnt+1));
                vis[np][nl][nw] = true;
            }
        }
    }
    return false;
}

int main() {
    while(cin>>pile>>len>>wid) {
        mes(vis,0);
        mes(maze,0);
        if(pile == 0 && len == 0 && wid == 0)
            break;
        qwq(1,pile+1)
            qeq(1,len+1)
                qsq(1,wid+1) {
                    cin>>maze[i][j][s];
                    if(maze[i][j][s] == 'S') { sp = i; sl = j; sw = s; }
                    if(maze[i][j][s] == 'E') { ep = i; el = j; ew = s; }
                }

        if(!bfs()) {
            cout<<"Trapped!"<<endl;
        }
    }
}
