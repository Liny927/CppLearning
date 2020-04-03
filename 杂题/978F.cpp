/*
 * @Author: Hellcat
 * @Date: 2020-03-27 18:54:58
 * F. Mentors
 * https://codeforces.ml/contest/978/problem/F
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;

int a[N], b[N], ans[N];

int main() {
    int n, k; scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    sort(b + 1, b + n + 1);
    for(int i = 1; i <= n; i++)
        ans[i] = lower_bound(b+1, b+n+1, a[i]) - b - 1;
    while(k--) {
        int x, y; scanf("%d%d", &x, &y);
        if(a[x] < a[y]) ans[y]--;
        if(a[y] < a[x]) ans[x]--;
    }
    for(int i = 1; i <= n; i++) printf("%d ", ans[i]);
}
