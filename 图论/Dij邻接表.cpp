/*
 * @Author: Hellcat
 * @Date: 2020-02-02 22:06:01
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
#define INF 2147483647
using namespace std;

const int maxn = 100010, maxm = 500010;

int n, m, s;
int dis[maxn];
bool done[maxn];  // done[i] = 1 表示到结点i的最短路径已经找到

struct edge
{
    int from, to, w;
    edge(int a, int b, int c) : from(a), to(b), w(c) {}
};

vector<edge> e[maxm];

struct s_node{
    int id, n_dis;
    s_node(int a, int b) : id(a), n_dis(b) {}
    bool operator < (const s_node &a) const
    { return  n_dis > a.n_dis; }
};

void dijkstra() {
    for(int i = 1; i <= n; i++) { dis[i] = INF; done[i] = 0; }
    dis[s] = 0;
    priority_queue<s_node> q;
    q.push(s_node(s, dis[s]));
    while(q.size()) {
        s_node u = q.top(); q.pop();
        if(done[u.id])
            continue;
        done[u.id] = 1;
        for(int i = 0; i < e[u.id].size(); i++) {
            edge y = e[u.id][i];
            if(done[y.to])
                continue;
            if(dis[y.to] > y.w + u.n_dis) {
                dis[y.to] = y.w + u.n_dis;
                q.push(s_node(y.to, dis[y.to]));
            }
        }
    }
    for(int i = 1; i <= n; i++)
        printf("%d ",dis[i]);
}

int main() {
    scanf("%d%d%d", &n, &m, &s);
    while(m--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        e[a].push_back(edge(a,b,c));
        // addedge(b,a,c);
    }
    dijkstra();
}
