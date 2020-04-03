/*
 * @Author: Hellcat
 * @Date: 2020-03-28 10:11:12
 * 	D - Almost Arithmetic Progression
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N];

int main() {
    int res = INT_MAX;
    int n; scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    if(n <= 2) return puts("0"), 0;
    for(int i = -1; i <= 1; i++)
        for(int j = -1; j <= 1; j++) {
            int d = a[2] + j - (a[1] + i);
            int s = abs(i);
            for(int k = 2; k <= n; k++) {
                int x = a[k] - (a[1]+i+(k-1)*d);
                if(abs(x) > 1) break;
                s += abs(x);
                if(k == n) res = min(res, s);
            }
        }
    if(res == INT_MAX) puts("-1");
    else printf("%d\n", res);
}
