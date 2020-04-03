/*
 * @Author: Hellcat
 * @Date: 2020-02-25 14:34:48
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int f[110][110];
int w[110][110];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            scanf("%d", &w[i][j]);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(i == 1 && j == 1) f[i][j] = w[i][j]; // min在入口处需要特判 不然会走到边界之外
            else {
                f[i][j] = 0x3f3f3f3f;
                if(i > 1) f[i][j] = min(f[i][j], f[i-1][j] + w[i][j]);
                if(j > 1) f[i][j] = min(f[i][j], f[i][j-1] + w[i][j]);
            }
    printf("%d\n", f[n][n]);
}
