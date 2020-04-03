/*
 * @Author: Hellcat
 * @Date: 2020-02-03 15:57:52
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
using namespace std;

const int maxn = 6010;
vector<int> mq[maxn];
int dp[maxn][2];

void dfs(int cur, int p) {
    // 搜索当前结点所有子节点
    for(int i = 0; i < mq[cur].size(); i++) {
        // 取出子节点
        int next = mq[cur][i];
        if(next == p) continue;
        dfs(next,cur);
        dp[cur][0] += max(dp[next][0], dp[next][1]); // 不选择当前结点
        dp[cur][1] += dp[next][0];     // 选择当前节点
    }
}

int main() {
    int n, a, b;
    while(~scanf("%d", &n)) {
        mes(dp,0);
        mes(mq,0);
        for(int i = 1; i <= n; i++)
            scanf("%d", &dp[i][1]); // conviviality rating
        while(~scanf("%d%d", &a, &b) && a != 0 && b != 0) {
            mq[a].push_back(b);
            mq[b].push_back(a);
        }
        dfs(1,0);
        cout<<max(dp[1][0],dp[1][1])<<endl;
    }
}