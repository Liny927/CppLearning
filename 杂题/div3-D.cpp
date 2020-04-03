#include <bits/stdc++.h>
using namespace std;

const int maxn = 4e5 + 10;
int a[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q, x;
    cin>>q>>x;
    int t, ans = 0;
    while(q--) {
        cin>>t;
        a[t % x]++;
        while(a[ans % x])
            a[ans % x]--, ans++;
            cout<<ans<<endl;
    }
}
