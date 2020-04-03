/*
 * @Author: Hellcat
 * @Date: 2020-02-03 13:42:20
 */
#include <bits/stdc++.h>
#pragma GCC optimize(2)
#define IOS ios::sync_with_stdio(false)
#define TIE cin.tie(0)
#define max(x,y) (x>y?x:y)
#define mes(a,b) memset(a,b,sizeof(a))
#define qwq(a,b) for(int i = (a); i < (b); ++i)
#define qeq(a,b) for(int j = (a); j < (b); ++j)
#define qaq(a,b) for(int k = (a); k > (b); --k)
// #define INF 0x3f3f3f3f
#define INF 11000
using namespace std;

const int maxn = 25100, maxm = 62100;
int n, m, s, t, cnt;
int head[maxm];
int dis[maxn];
int vis[maxn];
int pre[maxn];

struct Edge
{
	int to, next, w;
}edge[maxm];

void init() {
	qwq(0,maxm) {
		edge[i].next = -1;
		head[i] = -1;
	}
	cnt = 0;
}

void addedge(int u, int v, int w) {
	edge[cnt].to = v;
	edge[cnt].w = w;
	edge[cnt].next = head[u];
	head[u] = cnt++;
}

void spfa() {
	for(int i = 1; i <= n; i++) { dis[i] = INF; vis[i] = 0; }
	dis[s] = 0;
	queue<int> q;
	q.push(s);
	vis[s] = 1;
	while(q.size()) {
		int u = q.front(); q.pop();
		vis[u] = 0;
		for(int i = head[u]; ~i; i = edge[i].next) {
			int v = edge[i].to, w = edge[i].w;
			if(dis[u] + w < dis[v]) {
				dis[v] = dis[u] + w;
				if(!vis[v]) {
					vis[v] = 1;
					q.push(v);
				}
			}
		}
	}
	printf("%d\n", dis[t]);
}

int main() {
	scanf("%d%d%d%d", &n, &m, &s, &t);
	init();
	while(m--) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		addedge(a,b,c);
		addedge(b,a,c);
	}
	spfa();
}
