/*
 * @Author: Hellcat
 * @Date: 2020-02-08 13:14:01
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int to[8][2] = {{-2,-1}, {-1,-2}, {1,-2}, {2,-1}, {2,1}, {1,2}, {-1,2}, {-2,1}};
bool maze[55][55];
ll dp[55][55];

int main() {
    int n, m, x, y;
    scanf("%d%d%d%d", &n, &m, &x, &y);
    n += 2, m += 2, x += 2, y += 2;
    maze[x][y] = 1;
    for(int i = 0; i < 8; i++) {
        int nx = x + to[i][0];
        int ny = y + to[i][1];
        maze[nx][ny] = 1;
    }
    dp[1][2] = 1;
    for(int i = 2; i <= n; i++)
        for(int j = 2; j <= m; j++) {
            if(maze[i][j] != 1)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    printf("%lld\n", dp[n][m]);
}
