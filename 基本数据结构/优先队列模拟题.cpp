/*
 * @Author: Hellcat
 * @Date: 2020-02-01 14:26:09
 * HDU 1873
 */
#include <bits/stdc++.h>
#pragma GCC optimize(2)
#define IOS ios::sync_with_stdio(false)
#define TIE cin.tie(0)
#define max(x,y) (x>y?x:y)
#define mes(a,b) memset(a,b,sizeof(a))
#define qwq(a,b) for(int i = (a); i < (b); ++i)
#define qeq(a,b) for(int j = (a); j < (b); ++j)
#define qsq(a,b) for(int s = (a); s < (b); ++s)
#define qaq(a,b) for(int k = (a); k > (b); --k)
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int,int> P;

struct node {
    int num, id;
    friend bool operator < (node a, node b) {
        if(a.num != b.num)
            return a.num < b.num;
        else
            return a.id > b.id;
    }
};

int main() {
    int T;
    while(~scanf("%d", &T)) {
        // getchar();
        int cnt = 0;
        // priority_queue<int, pair<int,int> , less<int> > q;
        // priority_queue< pair<int,int> > q[5];
        priority_queue<node> q[5];
        mes(q,0);
        while(T--) {
            char s[10];
            int a, b;
            node t;
            scanf("%s", s);
            if(s[0] == 'I') {
                cnt++;
                scanf("%d%d", &a, &b);
                t.id = cnt;
                t.num = b;
                q[a].push(t);
            }
            if(s[0] == 'O') {
                scanf("%d", &a);
                if(q[a].empty()) puts("EMPTY");
                else {
                    cout<<q[a].top().id<<endl;
                    q[a].pop();
                }
            }
        }
    }
}
