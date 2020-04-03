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

int main() {
    ll n, m;
    scanf("%lld%lld", &n, &m);
    ll res = 0;
    res += 4 * ((n - 2) * (m - 1) % mod + (m - 2) * (n - 1) % mod) % mod;
    res += 2 * (m - 1) * (n - 2) % mod * (n - 2) % mod;
    res += 2 * (n - 1) * (m - 2) % mod * (m - 2) % mod;
    res += 2 * (m - 2) * (n - 1) % mod * (n - 2) % mod;
    res += 2 * (n - 2) * (m - 1) % mod * (m - 2) % mod;
    res = (res % mod + mod) % mod;
    printf("%lld\n", res % mod);
}
