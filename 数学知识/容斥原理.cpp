/*
 * @Author: Hellcat
 * @Date: 2020-03-26 18:11:46
 * HDOJ模板题
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 15;

ll n, m;
ll a[N];

int main() {
    while(~scanf("%lld%lld", &n, &m)) {
        ll res = 0;
        int k = 0;
        memset(a, 0, sizeof(a));
        for(int i = 0; i < m; i++) {
            int x; scanf("%lld", &x);
            if(x > 0 && x < n) a[k++] = x;
        }
        // 利用二进制枚举
        for(int i = 1; i < 1<<k; i++) {
            ll lcm = 1, cnt = 0, pos = 0; // cnt记录当前选法有几个集合
            for(int j = 0; j < m; j++)
                if(i >> j & 1) {
                    cnt++;
                    lcm = a[j] / __gcd(lcm, a[j]) * lcm;
                }
                if(cnt & 1) res += (n - 1) / lcm;
                else res -= (n - 1) / lcm;
        }
        printf("%lld\n", res);
    }
}
