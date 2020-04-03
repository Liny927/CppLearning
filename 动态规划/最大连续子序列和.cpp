/*
 * @Author: Hellcat
 * @Date: 2020-01-27 21:55:51
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
typedef long long LL;
typedef unsigned long long ULL;
using namespace std;

int A[10010];

struct node {
    int data; // dp[i] 数值
    int start; // 起始下标
    int end; // 结束下标
}dp[10010];

bool cmp(node a, node b) {
    return a.data > b.data;
}

int main() {
    int n;
    while(~scanf("%d", &n) && n) {
        mes(dp,0);
        int cnt = 0;     // 记录负数个数
        qwq(0,n) {
            scanf("%d", &A[i]);
            if(A[i] < 0) {
                cnt++;
            }
        }
        if(cnt == n) { cout<<0<<' '<<A[0]<<' '<<A[n - 1]<<endl; continue; }
        dp[0].data = A[0];
        dp[0].start = 0;
        dp[0].end = 0;
        for(int i = 1; i < n; i++) {
            if(A[i] > dp[i - 1].data + A[i]) {
                dp[i].data = A[i];
                dp[i].start = i;
                dp[i].end = i;
            }
            else {
                dp[i].data = dp[i - 1].data + A[i];
                dp[i].start = dp[i - 1].start;
                dp[i].end =i;
            }
        }
        sort(dp, dp + n, cmp);
        cout<<dp[0].data<<' '<<A[dp[0].start]<<' '<<A[dp[0].end]<<endl;
    }
}
