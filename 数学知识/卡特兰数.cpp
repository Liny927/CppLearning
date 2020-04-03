/*
 * @Author: Hellcat
 * @Date: 2020-02-27 15:54:37
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll C(int n, int m) {
    ll ans = 1;
    for(ll i = 1; i <= m; i++)
        ans = ans * (n - m + i) / i;
    return ans;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%lld\n", C(2*n, n) / (n + 1));
}