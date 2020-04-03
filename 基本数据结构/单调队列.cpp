/*
 * @Author: Hellcat
 * @Date: 2020-03-08 21:46:17
 */
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

int n, k;
int a[N], q[N];      // q数组存下标

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n>>k;
    for(int i = 0; i < n; i++) cin>>a[i];
    int hh = 0, tt = -1;
    for(int i = 0; i < n; i++) {
        if(hh <= tt && i - k + 1 > q[hh]) hh++;
        while(hh <= tt && a[q[tt]] >= a[i]) tt--;
        q[++tt] = i;
        if(i >= k - 1) printf("%d ", a[q[hh]]);
    }
    puts("");
    hh = 0, tt = -1;
    for(int i = 0; i < n; i++) {
        if(hh <= tt && i - k + 1 > q[hh]) hh++;
        while(hh <= tt && a[q[tt]] <= a[i]) tt--;
        q[++tt] = i;
        if(i >= k - 1) printf("%d ", a[q[hh]]);
    }
}
