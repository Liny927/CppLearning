/*
 * @Author: Hellcat
 * @Date: 2020-02-14 21:40:48
 */
#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-6;
const int maxn = 1e5 + 10;
double x[maxn], y[maxn];

int n;

double f(double mid) {
    double dis = 0;
    for(int i = 1; i <= n; i++)
        dis = max(dis,sqrt(y[i]*y[i] + (x[i]-mid)*(x[i]-mid)));
    return dis;
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%lf%lf", &x[i], &y[i]);
    double l = -1e4, r = 1e4, mid1, mid2;
    while(r - l > eps) {
            mid1 = l + (r - l) / 3;
            mid2 = r - (r - l) / 3;
            if(f(mid1) > f(mid2))
                l = mid1;
            else r = mid2;
    }
    printf("%.6f\n", f(l));
}
