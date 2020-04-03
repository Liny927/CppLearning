/*
 * @Author: Hellcat
 * @Date: 2020-02-03 13:43:30
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
const int INF = 0x3f3f3f3f;
const ll mod = 1e9+7;
const double pi = acos(-1.0);
const double eps = 1e-8;

vector<double> v1, v2;      // 分别存x y轴交点坐标

int main() {
    int x0, y0, n, k;
    scanf("%d%d%d%d", &x0, &y0, &n, &k);
    k = n - k; // 交点个数
    double x, y;
    qwq(0,n) {
        scanf("%lf%lf", &x, &y);
        if(x * x0 < 0) v2.push_back(y0 - x0 * (y - y0) / (x - x0));
        if(y * y0 < 0) v1.push_back(x0 - y0 * (x - x0) / (y - y0));
    }
    double mini = (double)INF;
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    if(v1.size() >= k) { // x
        double head = 0, tail = k - 1;  // 尺取
        while(tail < v1.size()) {
            mini = min(mini,  v1[tail] - v1[head]);
            tail++;
            head++;
        }
    }
    if(v2.size() >= k) { // y
        double head = 0, tail = k - 1;
        while(tail < v2.size()) {
            mini = min(mini, v2[tail] - v2[head]);
            tail++;
            head++;
        }
    }
    if(mini != INF) {
        printf("%.8f\n", mini);
    }
    else printf("-1\n");
}
