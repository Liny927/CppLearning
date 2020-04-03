/*
 * @Author: Hellcat
 * @Date: 2020-03-07 20:40:04
 */
#include <bits/stdc++.h>
using namespace std;

const int N = 1010, M = 1e6 + 10;

bool vis[N];  // ��ǵڶ��������еĵ��Ƿ񱻱���
/* �ڽӱ�洢���б�, �����������㷨��ֻ���õ��ӵ�һ
������ָ��ڶ������ϵıߣ���������ֻ�ô�һ������ı� */
int h[N], e[M], ne[M], idx;
int n, m, k;
int match[N];  // ��ԵĽ�� ���洢�ڶ��������е�ÿ���㵱ǰƥ�䵽��һ�������еĵ����ĸ�

inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch >'9') {
        if (ch == '-')f = -1;
        ch = getchar();
    }
    while (ch >= '0'&& ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return f * x;
}

bool dfs(int x) {              // �ڽӱ�
    for(int i = h[x]; ~i; i = ne[i]) {
        int j = e[i];
        if(!vis[i]) {
            vis[i] = true;
            if(!match[j] || dfs(match[j])) {
                match[j] = x;
                return true;
            }
        }
    }
    return false;
}

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    memset(h, -1, sizeof(h));
    memset(match, 0, sizeof(match));
    while(k--) {
        int a, b;
        a = read(); b = read();
        if(a > n || b > m || a > m || b > n) continue;
        add(a, b);
    }
    int res = 0;
    for(int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof(vis));
        if(dfs(i)) res++;
    }
    printf("%d\n", res);
}
