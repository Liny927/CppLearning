/*
 * @Author: Hellcat
 * @Date: 2020-02-01 16:09:55
 * HDU 2544
 */
#include <bits/stdc++.h>
#pragma GCC optimize(2)
#define IOS ios::sync_with_stdio(false)
#define TIE cin.tie(0)
#define max(x,y) (x>y?x:y)
#define mes(a,b) memset(a,b,sizeof(a))
#define qwq(a,b) for(int i = (a); i < (b); ++i)
#define qeq(a,b) for(int j = (a); j < (b); ++j)
#define qaq(a,b) for(int k = (a); k > (b); --k)
#define INF 0x3f3f3f3f
using namespace std;

const int NUM = 1005;
int maze[NUM][NUM];
int n, m, s;

void floyd() {
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            if(i != k && maze[i][k] != INF)
            for(int j = 1; j <= n; j++)
                if(maze[i][j] > maze[i][k] + maze[k][j])
                    maze[i][j] = maze[i][k] + maze[k][j];
}

inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while (ch<'0' || ch>'9') {
        if (ch == '-')f = -1;
        ch = getchar();
    }
    while (ch >= '0'&&ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return f * x;
}

inline void write(int x) {
    int y = 10, len = 1;
    while (y <= x) {
        y *= 10; len++;
    }
    while (len--) {
        y /= 10; putchar(x / y + 48); x %= y;
    }
}

int main() {
    n = read(); m = read(); s = read();
    mes(maze,INF);
    maze[s][s] = 0;
    while(m--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        maze[a][b] = min(maze[a][b],c);
    }
    floyd();
    qwq(1,n + 1) {
        printf("%d ", maze[s][i]);
    }
}

// 邻接矩阵适用于稠密图 存稀疏图会有大量空间被浪费