/*
 * @Author: Hellcat
 * @Date: 2020-03-05 20:24:51
 * 最长公共上升子序列 (LIS + LCS)
 */
#include <bits/stdc++.h>
using namespace std;

const int N = 510;
int n, m;
int a[N], b[N];
int f[N][N];
int path[N][N];

void print(int i, int j) {
    if(i == 0) return;
    print(i-1, path[i][j]);
    if(path[i][j] != j)
        printf("%d ", b[j]);
    return;
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    scanf("%d", &m);
    for(int i = 1; i <= m; i++)
        scanf("%d", &b[i]);
    for(int i = 1; i <= n; i++)
        for(int j = 1, k = 0; j <= m; j++) {
            if(a[i] == b[j]) {
                f[i][j] = f[i - 1][k] + 1;
                path[i][j] = k;
            }
            else {
                f[i][j] = f[i - 1][j];
                path[i][j] = j;
            }
            if(b[j] < a[i] && f[i][j] > f[i][k])
                k = j;
        }
    int ansj = 0;
    for(int i = 1; i <= m; i++) {
        if(f[n][i] > f[n][ansj])
            ansj = i;
    }
    printf("%d\n", f[n][ansj]);
    print(n, ansj);
}
