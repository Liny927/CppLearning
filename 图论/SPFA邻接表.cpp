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

const int maxn = 10010;

int n, m, s;
int dis[maxn];  // 记录所有节点到起点距离
int neg[maxn];  // 判断负圈
bool vis[maxn]; // 结点i是否在队列中

struct edge
{
    int from, to, w;
    edge(int a, int b, int c) : from(a), to(b), w(c) {}
};

vector<edge> e[maxn];

int spfa() {
    mes(neg,0);
    neg[s] = 1;
    for(int i = 1; i <= n; i++) { dis[i] = INF; vis[i] = 0; }
    dis[s] = 0;
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    while(q.size()) {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        qwq(0,e[u].size()) {
            int v = e[u][i].to , w = e[u][i].w;
            if(dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                if(!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                    neg[v]++;
                    if(neg[v] > n) return 1; // 负圈
                }
            }
        }
    }
    for(int i = 1; i <= n; i++)
        printf("%d ",dis[i]);
    return 0;
}

// int main() {
//     while(~scanf("%d%d", &n, &m)) {
//         s = 1;
//         if(n == 0 && m == 0) return 0;
//         qwq(1,n + 1) e[i].clear();
//         while(m--) {
//             int a, b, c;
//             scanf("%d%d%d", &a, &b, &c);
//             e[a].push_back(edge(a,b,c));
//             e[b].push_back(edge(b,a,c));
//         }
//         spfa();
//     }
// }

int main() {
    scanf("%d%d%d", &n, &m, &s);
    while(m--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        e[a].push_back(edge(a,b,c));
        // addedge(b,a,c);
    }
    spfa();
}
