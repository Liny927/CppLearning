/*
 * @Author: Hellcat
 * @Date: 2020-01-27 20:48:55
 * HDU 1069
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
using namespace std;

int dp[11000];
int cnt = 0;

struct node {
    int x, y, h;
}block[11000];

bool cmp(node a, node b) {
    if(a.x != b.x)
        return a.x > b.x;
    return a.y > b.y;
}

void init(int x, int y, int h) {
    block[cnt].x = x;
    block[cnt].y = y;
    block[cnt].h = h;
    cnt++;
}

int main() {
    int n;
    int ans_cnt = 0;
    while(~scanf("%d", &n) && n) {
        mes(dp,0);
        mes(block,0);
        cnt = 0;
        int x, y, h;
        qwq(0,n) {
            scanf("%d%d%d", &x, &y, &h);
            init(x,y,h);
            init(x,h,y);
            init(y,x,h);
            init(y,h,x);
            init(h,y,x);
            init(h,x,y);
        }
        sort(block, block + cnt, cmp);
        qwq(0,cnt)
            dp[i] = block[i].h;
        for(int i = 0; i < cnt; i++)
            for(int j = i; j > 0; j--) {
                if(block[j].x > block[i].x && block[j].y > block[i].y)
                    dp[i] = max(dp[i], dp[j] + block[i].h);
            }
        int ans = -1;
        qwq(0,cnt)
            ans = max(ans, dp[i]);
        ans_cnt++;
        printf("Case %d: maximum height = %d\n", ans_cnt ,ans);
    }
}
