/*
 * @Author: Hellcat
 * @Date: 2020-03-04 16:57:13
 */
#include <bits/stdc++.h>
using namespace std;

int a[1010], f[1010], g[1010];

int main() {
    int n; scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for(int i = 1; i <= n; i++) {
        f[i] = 1;
        for(int j = 1; j < i; j++)
            if(a[i] > a[j])
                f[i] = max(f[i], f[j] + 1);
    }
    for(int i = n; i >= 1; i--) {
        g[i] = 1;
        for(int j = n; j > i; j--)
            if(a[i] > a[j])
                g[i] = max(g[i], g[j] + 1);
    }
    int res = 0;
    for(int i = 1; i <= n; i++)
        res = max(res, f[i] + g[i] - 1);
    printf("%d\n", res);
}
