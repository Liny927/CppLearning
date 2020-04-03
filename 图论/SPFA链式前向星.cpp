/*
 * @Author: Hellcat
 * @Date: 2020-02-03 12:19:30
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
// #define INF 0x3f3f3f3f
#define INF 2147483647
using namespace std;

const int maxn = 10010, maxm = 500010;

int n, m, s, cnt = 0;
int head[maxm];
int dis[maxn];  // ��¼���нڵ㵽������
int neg[maxn];  // �жϸ�Ȧ
bool inq[maxn]; // ���i�Ƿ��ڶ�����
int pre[maxn];  // ��¼ǰ�����

struct Edge
{
    int to, next, w;
}edge[maxm];

void init() {
    qwq(0,maxm) {
        edge[i].next = -1;  // -1:���� û����һ����
        head[i] = -1;       // -1:�����ڴӽ��i�����ı�
    }
    cnt = 0;
}

void addedge(int u, int v, int w) { // ��ʽǰ���Ǵ�ͼ
    edge[cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].next = head[u];  // ָ��u��һ�δ�ıߵ�λ��
    head[u] = cnt++;
}

void spfa() {
    // mes(neg,0);
    // neg[s] = 1;
    for(int i = 1; i <= n; i++) { dis[i] = INF; inq[i] = 0; }
    dis[s] = 0;
    queue<int> q;
    q.push(s);
    inq[s] = 1;
    while(q.size()) {
        int u = q.front();
        q.pop();
        inq[u] = 0;
        for(int i = head[u]; ~i; i = edge[i].next) {
            int v = edge[i].to, w = edge[i].w;
            if(dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                if(!inq[v]) {
                    inq[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    // printf("%d\n",dis[n]);
    qwq(1,n + 1)
        printf("%d ",dis[i]);
}

int main() {
    scanf("%d%d%d", &n, &m, &s);
    init();
    while(m--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        addedge(a,b,c);
        // addedge(b,a,c);
    }
    spfa();
}

// int main() {
//     while(~scanf("%d%d", &n, &m)) {
//         init();
//         s = 1;
//         if(n == 0 && m == 0) return 0;
//         while(m--) {
//             int a, b, c;
//             scanf("%d%d%d", &a, &b, &c);
//             addedge(a,b,c);
//             addedge(b,a,c);
//         }
//         spfa();
//     }
// }
