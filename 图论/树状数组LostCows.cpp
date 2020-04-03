/*
 * @Author: Hellcat
 * @Date: 2020-03-15 23:32:36
 */
#include <iostream>
#include <cstdio>
using namespace std;

const int N = 1e5 + 10;

int n, h[N], ans[N], tr[N];

inline int lowbit(int x) {
    return x & -x;
}

void add(int x, int v) {
    for(int i = x; i <= n; i += lowbit(i)) tr[i] += v;
}

int sum(int x) {
    int res = 0;
    for(int i = x; i; i -= lowbit(i)) res += tr[i];
    return res;
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        if(i > 1) scanf("%d", &h[i]);
        add(i, 1);
    }
    for(int i = n; i; i--) {
        int k = h[i] + 1;
        int l = 1, r = n;
        while(r - l > 0) {
            int mid = (l + r) >> 1;
            if(sum(mid) >= k) r = mid;
            else l = mid + 1;
        }
        ans[i] = r;
        add(r, -1);
    }
    for(int i = 1; i <= n; i++)
        printf("%d\n", ans[i]);
}
