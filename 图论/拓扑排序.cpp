/*
 * @Author: Hellcat
 * @Date: 2020-01-23 10:24:40
 * UVa 10305
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

const int maxn = 1010;
int n, m, G[maxn][maxn], c[maxn], topo[maxn], t;

bool dfs(int u) {
  c[u] = -1;
  for(int v = 0; v < n; v++) if(G[u][v]) {
    if(c[v] < 0) return 0;
    else if(!c[v]) dfs(v);
  }
  c[u] = 1;
  topo[--t] = u;
  return 1;
}

bool toposort() {
  t = n;
  mes(c,0);
  for(int u = 0; u < n; u++) if(!c[u])
    if(!dfs(u)) return 0;
  return 1;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  while(cin>>n>>m) {
    if(n == 0 && m == 0) break;
    mes(G,0);
    int u, v;
    while(m--) {
      cin>>u>>v;
      u--; v--;
      G[u][v] = 1;
    }
    if(toposort()) {
      qwq(0,n-1)
        printf("%d ",topo[i]+1);
      printf("%d\n",topo[n-1]+1);
    }
  }
}