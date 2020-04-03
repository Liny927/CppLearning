/*
 * @Author: Hellcat
 * @Date: 2019-12-23 20:01:34
 * UVA 572 连通图问题
 */

#pragma GCC optime(2)
#include <iostream>
#include <string.h>
#include <string>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
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

char maze[110][110];
int to[8][2] = {
    {0, -1}, {0, 1}, {1, 0}, {1, -1}, {1, 1}, {-1, 0}, {-1, -1}, {-1, 1},
};
int n, m, t;
int sx, sy;  //搜索起点坐标
//int fx, fy;  //终点坐标
int res = 0;

void dfs(int si, int sj) {
	maze[si][sj] = '.';
	qwq(0,8) {
		int nx = si + to[i][0];
		int ny = sj + to[i][1];
		if (0 <= nx && nx < n && 0 <= ny && ny < m && maze[nx][ny] == 'W')
				dfs(nx, ny);
	}
	return;
}

int main() {
	while(scanf("%d%d", &n, &m) == 2 && m && n) {
		res = 0;
		mes(maze,'\0');
		qwq(0,n) {
			cin>>maze[i];
		}
		qwq(0,n)
			qeq(0,m)
				if(maze[i][j] == 'W') dfs(i,j),res++;
		cout<<res<<endl;
	}
}