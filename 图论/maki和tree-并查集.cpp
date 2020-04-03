/*
 * @Author: Hellcat
 * @Date: 2020-02-05 23:01:36
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
typedef long long ll;
const int maxn = 1e5 + 10;

vector<int> maze[maxn];   // 存图
bool has[maxn];  // 记录顶点i是否为黑色
char s[maxn];
int bin[maxn];
ll num[maxn];  // num维护编号i所在列有多少顶点

int find(int x) {
    return x == bin[x] ? x : bin[x] = find(bin[x]);
}

void merge(int x, int y) {
    int fx = find(x), fy = find(y);
    if(fx != fy) {
        bin[fx] = fy;
        num[fy] += num[fx];
    }
}

int main() {
    int n;
    scanf("%d", &n);
    qwq(0,n+1) bin[i] = i, num[i] = 1;
    scanf("%s", s + 1);
    qwq(1,n+1)
        if(s[i] == 'B') has[i] = 1;
    qwq(0,n-1) {
        int u, v;
        scanf("%d%d", &u, &v);
        maze[u].push_back(v);
        maze[v].push_back(u);
        if(!has[u] && !has[v])
            merge(u,v);     // 合并连通图内的白色块
    }
    ll res = 0;
    qwq(1,n+1) {    // 根据容斥原理计算
        if(!has[i]) continue;
        ll cnt = 0; // 已有的白点总数
        for(auto it : maze[i]) {
            if(has[it]) continue;
            res += cnt * num[find(it)];
            cnt += num[find(it)];
        }
        res += cnt;
    }
    cout<<res<<endl;
}
