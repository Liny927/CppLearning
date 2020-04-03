/*
 * @Author: Hellcat
 * @Date: 2020-02-15 14:19:50
 * luogu P1546
 */
#include <bits/stdc++.h>
using namespace std;

int n, ans;
int mp[110][110];  // �ڽӾ�����
bool vis[110];    // �洢ÿ�����Ƿ�����������
int dis[110];     // �洢�����㵽��ǰ��С�������ľ���

void Prim() {
    dis[1] = 0;
    for(int i = 1; i < n; i++) {
        int x = 0;
        for(int j = 1; j <= n; j++)
            if(!vis[j] && (x == 0 || dis[j] < dis[x])) x = j;
        vis[x] = 1;
        for(int y = 1; y <= n; y++)
            if(!vis[y]) dis[y] = min(dis[y], mp[x][y]);
    }
}

int main() {
    memset(dis, 0x3f, sizeof(dis));
    memset(mp, 0x3f, sizeof(mp));
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            scanf("%d", &mp[i][j]);
    Prim();
    for(int i = 2; i <= n; i++)
        ans += dis[i];
    printf("%d\n", ans);
}
