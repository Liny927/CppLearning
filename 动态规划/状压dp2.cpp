/*
 * @Author: Hellcat
 * @Date: 2020-02-10 11:22:44
 */
// << | & ^ ~ -
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;

int n, m;
string s;
int mp[110];
vector<int> legal;  // 储存所有的合法01串
int dp[6][1100][1100];

void init() {    // 找到合法的摆放总数
    for(int i = 0; i < (1<<m); i++) { // 1<<m == pow(2,m)
        int c1 = 3, c2 = 5; // 3 -> (0011) , 5 -> (0101)
        bool sub = 1;
        for(int j = 0; j < m - 1; j++) {
            if(((i >> j) & c1) == c1) {
                sub = 0;
            }
        }
        for(int j = 0; j < m - 2; j++) {
            if(((i >> j) & c2) == c2) {
                sub = 0;
            }
        }
        if(sub) legal.push_back(i);
    }
}

int count(int x) {
    int cnt = 0;
    for(int i = 0; i < m; i++) {
        if(((x>>i)&1) == 1) {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    cin>>n>>m;
    init();
    // cout<<legal.size()<<endl;
    for(int i = 2; i <= n + 1; i++) {  // i初值2 避免越界
        cin>>s;
        for(int j = 0; j < m; j++)
            if(s[j] == 'H') mp[i] |= (1<<j);
    }
    for(int i = 2; i <= n + 1; i++) {
        for(auto step : legal) {
            if((step & mp[i]) != 0) continue;
            for(auto bst : legal) {
                if((step & bst) != 0) continue;
                if((bst & mp[i-1]) != 0) continue;
                for(auto bbst : legal) {
                    if((step & bbst) != 0) continue;
                    if((bbst & mp[i-2]) != 0) continue;
                    if((bbst & bst) != 0) continue;
                    dp[i%3][step][bst] = max(dp[(i-1)%3][bst][bbst] + count(step), dp[i%3][step][bst]);
                }
            }
        }
    }
    int res = 0;
    for(auto step : legal)
        for(auto bst : legal)
            res = max(res, dp[(n+1)%3][step][bst]);
    cout<<res<<endl;
}
