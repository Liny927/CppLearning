/*
 * @Author: Hellcat
 * @Date: 2020-02-04 11:12:12
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
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

int M, N, top = 0;    // top表示每行最多的状态数
int state[600], num[110];
int dp[20][600];
int cur[20]; // 第i行整行的情况
const int mod = 100000000;

inline bool check(int x) {
    if(x & x<<1) return false;
    return true;
}

inline bool fit(int x, int k) {
    if(x & cur[k]) return false; // 重合
    return true;
}

void init() {
    top = 0;
    int total = 1 << N;  // 2^N种情况
    qwq(0,total) {
        if(check(i))
            state[++top] = i;
    }
}

int main() {
    while(~scanf("%d%d", &M, &N)) {
        init();
        mes(dp,0);
        for(int i = 1; i <= M; i++) {
            cur[i] = 0;
            int num;
            for(int j = 1; j <= N; j++) {
                scanf("%d", &num);
                if(num == 0)
                    cur[i] += (1<<(N-j));
            }
        }
        for(int i = 1; i <= top; i++)
            if(fit(state[i],1))
                dp[1][i] = 1;
        for(int i = 2; i <= M; i++) {
            for(int k = 1; k <= top; k++) {
                if(!fit(state[k],i)) continue;
                for(int j = 1; j <= top; j++) {
                    if(!fit(state[j], i - 1)) continue;
                    if(state[k] & state[j]) continue;
                    dp[i][k] = (dp[i][k] + dp[i-1][j]) % mod;
                }
            }
        }
        int ans = 0;
        for(int i = 1; i <= top; i++) {
            ans = (ans + dp[M][i]) % mod;
        }
        cout<<ans<<endl;
    }
}