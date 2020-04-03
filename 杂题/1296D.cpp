/*
 * @Author: Hellcat
 * @Date: 2020-02-05 17:34:20
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

int main() {
    int n, a, b, k;
    scanf("%d%d%d%d", &n, &a, &b, &k);
    vector<int> h(n);
    qwq(0,n) {
        scanf("%d", &h[i]);
        h[i] %= (a + b);
        if(h[i] == 0) h[i] += a + b;
        h[i] = ceil((double)h[i] / a) - 1;
    }
    sort(h.begin(), h.end());
    int ans = 0;
    qwq(0,n) {
        if(k - h[i] < 0) break;
        ans++;
        k -= h[i];
    }
    cout<<ans<<endl;
}
