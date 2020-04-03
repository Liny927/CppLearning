/*
 * @Author: Hellcat
 * @Date: 2020-02-25 14:34:48
 */
//#include <bits/stdc++.h>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1e5 + 10;
int n, l;
int a[maxn];
double sum[maxn];

bool check(double avg) {
    for(int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + a[i] - avg;
        double minv = 0;
        for(int i = 0, j = l; j <= n; j++, i++) { // ³ßÈ¡
            minv = min(minv, sum[i]);
            if(sum[j] >= minv) return true;
        }
    return false;
}

int main() {
    scanf("%d%d", &n, &l);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    double l = 0, r = 2000;
    while(r - l > 1e-6) { // ¶þ·Ö
          double mid = (l + r) / 2;
          if(check(mid)) l = mid;
          else r = mid;
    }
    printf("%d\n", int(r * 1000));
}