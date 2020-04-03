/*
 * @Author: Hellcat
 * @Date: 2020-03-05 12:14:53
 */
#include <bits/stdc++.h>
using namespace std;

int n;
const int N = 1e5 + 10;
int a[N], f[N], g[N];

int main() {
    while(~scanf("%d", &a[++n]))
        ;
    n--;
    int len1 = 1, len2 = 1;
    f[1] = a[1];
    g[1] = a[1];
    for(int i = 2; i <= n; i++) {
        if(a[i] <= f[len1])
            f[++len1] = a[i];
        else {
            int j = upper_bound(f + 1, f + len1 + 1, a[i], greater<int>()) - f;
            f[j] = a[i];
        }
        if(a[i] > g[len2])
            g[++len2] = a[i];
        else {
            int k = lower_bound(g + 1, g + len2 + 1, a[i]) - g;
            g[k] = a[i];
        }
    }
    printf("%d\n%d\n", len1, len2);
}

/*
 * @Author: Hellcat
 * @Date: 2020-03-05 12:14:53
 */
#include <bits/stdc++.h>
using namespace std;

int n;
int a[1010], f[1010], g[1010];

int main() {
    while(~scanf("%d", &a[n])) n++;
    int res = 0;
    for(int i = 0; i < n; i++) {
        f[i] = 1;
        for(int j = 0; j < i; j++)
            if(a[j] >= a[i])
                f[i] = max(f[i], f[j] + 1);
        res = max(res, f[i]);
    }
    printf("%d\n", res);
    res = 0;
    for(int i = 0; i < n; i++) {
        g[i] = 1;
        for(int j = 0; j < i; j++)
            if(a[j] < a[i])
                g[i] = max(g[i], g[j] + 1);
        res = max(res, g[i]);
    }
    printf("%d\n", res);
}