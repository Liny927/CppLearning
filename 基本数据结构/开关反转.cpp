/*
 * @Author: Hellcat
 * @Date: 2020-02-15 14:19:50
 */
#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f

char maze[10][10];
int to[5][2] = { {0, 0}, {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

void turn(int x, int y) {
    for(int i = 0; i < 5; i++) {
        int nx = x + to[i][0];
        int ny = y + to[i][1];
        if(nx >= 0 && nx < 5 && ny >= 0 && ny < 5) {
            maze[nx][ny] ^= 1;
        }
    }
}

int solve() {
    int ans = inf;
    for(int k = 0; k < 1 << 5; k++) {
        int res = 0;
        char backup[10][10];
        memcpy(backup, maze, sizeof(maze));
        for(int j = 0; j < 5; j++)
            if(k >> j & 1) {
                res++;
                turn(0, j);
            }
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 5; j++)
                if(maze[i][j] == '0') {
                    res++;
                    turn(i + 1, j);
                }
        bool ok = true;
        for(int j = 0; j < 5; j++)
            if(maze[4][j] == '0') {
                ok = 0;
                break;
            }
        if(ok)
            ans = min(ans, res);
        memcpy(maze, backup, sizeof(maze));
    }
    if(ans > 6) return -1;
    return ans;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        for(int i = 0; i < 5; i++)
            scanf("%s", maze[i]);
        printf("%d\n", solve());
    }
}
