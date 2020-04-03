/*
 * @Author: Hellcat
 * @Date: 2020-02-04 13:09:14
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
const ll mod = 1e9 + 7;
const ll maxn = 3e5 + 10;

char s[maxn];
ll n, a, b, c;
char dir[3][20] = {"nico", "niconi", "niconiconi"};
ll dp[maxn];

int main(){
    int n;
    scanf("%d", &n);
    ll a, b, c;
    scanf("%lld%lld%lld", &a, &b, &c);
    scanf("%s",s + 1);
    dp[0] = 0;
    for(int i = 1;i <= n;i++){
        if(i >= 4){
            if(s[i] == 'o' && s[i - 1] == 'c' && s[i - 2] == 'i' && s[i - 3] == 'n') dp[i] = max(dp[i - 4] + a,dp[i]);
        }
        if(i >= 6){
            if(s[i - 5] == 'n' && s[i - 4] == 'i' && s[i - 3] == 'c' && s[i - 2] == 'o' && s[i - 1] == 'n' && s[i] == 'i') dp[i] = max(dp[i - 6] + b,dp[i]);
        }
        if(i >= 10){
            if(s[i - 9] == 'n' && s[i - 8] == 'i' &&s[i - 7] == 'c' &&s[i - 6] == 'o' &&s[i - 5] == 'n' && s[i - 4] == 'i' && s[i - 3] == 'c' && s[i - 2] == 'o' && s[i - 1] == 'n' && s[i] == 'i') dp[i] = max(dp[i - 10] + c,dp[i]);
        }
        dp[i] = max(dp[i -1],dp[i]);
    }
    printf("%lld\n",dp[n]);
}