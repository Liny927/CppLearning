/*
 * @Author: Hellcat
 * @Date: 2020-01-28 16:39:16
 */
#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#pragma GCC optimize(2)
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
#define INF 0x3f3f3f3f
typedef long long LL;
typedef unsigned long long ULL;
using namespace std;

priority_queue<LL, vector<LL>, greater<LL> > q;

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n;
        while(q.size()) q.pop();
        LL tmp, x, y, ans = 0;
        scanf("%d", &n);
        qwq(0,n) {
            scanf("%d", &tmp);
            q.push(tmp);
        }
        while(q.size() > 1) {
            x = q.top();
            q.pop();
            y = q.top();
            q.pop();
            q.push(x + y);
            ans += x + y;
        }
    cout<<ans<<endl;
    }
}
