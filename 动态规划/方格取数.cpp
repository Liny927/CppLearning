/*
 * @Author: Hellcat
 * @Date: 2020-02-17 16:15:34
 */
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int w[25][25];
int f[25 * 2][25][25];

int main() {
    int n;
    scanf("%d", &n);
    int x, y, val;
    while(~scanf("%d%d%d", &x, &y, &val)) {
        if(x == 0 && y == 0) break;
        w[x][y] = val;
    }
    for(int k = 2; k <= n + n; k++)
        for(int i1 = 1; i1 <= n; i1++)
            for(int i2 = 1; i2 <= n; i2++) {
                int j1 = k - i1, j2 = k - i2;
                if(j1 >= 1 && j1 <= n && j2 >= 1 && j2 <= n) {
                    int t = w[i1][j1];
                    if(i1 != i2) t += w[i2][j2];
                    f[k][i1][i2] = max(f[k][i1][i2], f[k-1][i1-1][i2-1] + t);
                    f[k][i1][i2] = max(f[k][i1][i2], f[k-1][i1-1][i2] + t);
                    f[k][i1][i2] = max(f[k][i1][i2], f[k-1][i1][i2-1] + t);
                    f[k][i1][i2] = max(f[k][i1][i2], f[k-1][i1][i2] + t);
                }
            }
    printf("%d\n", f[n+n][n][n]);
}
