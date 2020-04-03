/*
 * @Author: Hellcat
 * @Date: 2020-02-06 12:59:40
 */
#include <bits/stdc++.h>
#pragma GCC optimize(2)
#define IOS ios::sync_with_stdio(false)
#define TIE cin.tie(0)
#define min(x,y) (x>y?y:x)
#define mes(a,b) memset(a,b,sizeof(a))
#define qwq(a,b) for(int i = (a); i < (b); ++i)
#define qeq(a,b) for(int j = (a); j < (b); ++j)
#define qsq(a,b) for(int s = (a); s < (b); ++s)
#define qaq(a,b) for(int k = (a); k > (b); --k)
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;

int x[200], y[200];

bool check(int i, int j, int k) {
    // 点积<0 叉积!=0 (确保不共线)
    return ((x[j] - x[i]) * (x[k] - x[i]) + (y[j] - y[i]) * (y[k] - y[i]) < 0) && ((x[j] - x[i]) * (y[k] - y[i]) - (x[k] - x[i]) * (y[j] - y[i]) != 0);
}

int main() {
    int n, res = 0;
    scanf("%d", &n);
    qwq(0,n) {
        scanf("%d%d", &x[i], &y[i]);
    }
    qwq(0,n)
        qeq(i+1,n)
            for(int k = j + 1; k < n; k++) {
                if(check(i,j,k) || check(j,i,k) || check(k,i,j))
                    res++;
            }
    cout<<res<<endl;
}
