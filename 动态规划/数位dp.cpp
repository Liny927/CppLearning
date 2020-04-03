/*
 * @Author: Hellcat
 * @Date: 2020-02-03 19:45:03
 * 没有49
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

__int64 dp[32][12];  // dp[i][j]表示i位数 第1个数是j时数字数量
int digit[32];

void init() {
    mes(dp,0);
    dp[0][0] = 1;
    for(int i = 1; i <= 25; i++)
        for(int j = 0; j < 10; j++)
            for(int k = 0; k < 10 ;k++)
                if(j != 4 || k != 9)
                    dp[i][j] += dp[i - 1][k];
}

__int64 solve(__int64 x) {
    __int64 ans = 0;
    int len = 0;
    while(x) {
        digit[++len] = x % 10;
        x /= 10;
    }
    for(int i = len; i >= 1; i--) {
        for(int j = 0; j < digit[i]; j++) {
            if(j != 9 || digit[i + 1] != 4)
                ans += dp[i][j];
        }
        if(digit[i] == 9 && digit[i + 1] == 4) {
            // ans--;
            break;
        }
    }
    return ans;
}

int main() {
    int T;
    __int64 n;
    init();
    scanf("%d", &T);
    while(T--) {
        mes(digit,0);
        scanf("%I64d", &n);
        printf("%I64d\n", n + 1 - solve(n + 1));
    }
}
