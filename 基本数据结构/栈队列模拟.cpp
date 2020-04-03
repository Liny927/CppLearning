/*
 * @Author: Hellcat
 * @Date: 2020-02-01 14:26:09
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

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        stack<int> sta;
        queue<int> que;
        if(sta.size()) sta.pop();
        if(que.size()) que.pop();
        int n, x;
        char s[10], st[10];
        scanf("%d%s", &n, s);
        if(s[2] == 'L') {
            while(n--) {
                scanf("%s", st);
                if(st[0] == 'I') { scanf("%d", &x); sta.push(x); }
                if(st[0] == 'O') { if(sta.empty()) puts("None"); else{ printf("%d\n", sta.top()); sta.pop(); } }
            }
        }
        if(s[2] == 'F') {
            while(n--) {
                scanf("%s", st);
                if(st[0] == 'I') { scanf("%d", &x); que.push(x); }
                if(st[0] == 'O') { if(que.empty()) puts("None"); else { printf("%d\n", que.front()); que.pop(); } }
            }
        }
    }
}