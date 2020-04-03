/*
 * @Author: Hellcat
 * @Date: 2020-02-04 14:47:49
 */
#include<bits/stdc++.h>
#define max(x,y) (x>y?x:y)
#define mes(a,b) memset(a,b,sizeof(a))
#define qwq(a,b) for(int i = (a); i < (b); ++i)
#define qeq(a,b) for(int j = (a); j < (b); ++j)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn = 3e5+10;
const ll mod = 1e9+7;
typedef pair<int, int> P;

char s[1000001];

int main() {
    int T, n;
    char ch;
    scanf("%d", &T);
    while(T--) {
        int x = 0, y = 0;
        scanf("%d", &n);
        cin>>s+1;
        map<P,int> mp;  // 建立坐标-字符串的对应关系
        mp[P(0,0)] = 1;
        int ans = n + 1, l, r;
        for(int i = 1; i <= n; i++) {
            if(s[i] == 'L') x--;
            if(s[i] == 'R') x++;
            if(s[i] == 'U') y++;
            if(s[i] == 'D') y--;
            int k = mp[P(x,y)];
            if(k) {
                if(i - k + 1 < ans) {
                    ans = i - k + 1;
                    l = k, r = i;
                }
            }
            mp[P(x,y)] = i + 1;
        }
        if(ans == n + 1) puts("-1");
        else printf("%d %d\n", l, r);
    }
}
