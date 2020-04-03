/*
 * @Author: Hellcat
 * @Date: 2020-02-01 16:09:55
 */
#include <bits/stdc++.h>
#pragma GCC optimize(2)
#define IOS ios::sync_with_stdio(false)
#define TIE cin.tie(0)
#define max(x,y) (x>y?x:y)
#define mes(a,b) memset(a,b,sizeof(a))
#define qwq(a,b) for(int i = (a); i < (b); ++i)
#define qeq(a,b) for(int j = (a); j < (b); ++j)
#define qsq(a,b) for(int s = (a); s < (b); ++s)
#define qaq(a,b) for(int k = (a); k > (b); --k)
#define INF 0x3f3f3f3f
using namespace std;
#define eps 1e-8
int sgn(int x) {     // 判断x是否等于0
	if(fabs(x) < eps) return 0;
	else return x < 0 ? -1 : 1;
}


struct Point
{
    double x, y;
}P[1001];

// 向量
typedef Point Vector;

double Cross(Vector A, Vector B) { return A.x*B.y - A.y*B.x; }

bool Parallel(Vector A, Vector B) { return sgn(Cross(A, B)) == 0; }

int main() {
    int n;
    scanf("%d", &n);
    if(n <= 2) { cout<<n<<endl; return 0; }
    qwq(0,n) {
        scanf("%lf%lf", &P[i].x, &P[i].y);
    }
    int res = 2;
    int cnt;
    Vector v1, v2;
    qwq(0,n-1)
        qeq(i+1,n) {
            cnt = 2;
            v1.x = P[j].x - P[i].x;
            v1.y = P[j].y - P[i].y;
            for(int k = 0; k < n; k++) {
                if(k == i || k == j) continue;
                v2.x = P[k].x - P[i].x;
                v2.y = P[k].y - P[i].y;
                if(Parallel(v1, v2)) cnt++;
            }
        res = max(cnt,res);
    }
    cout<<res<<endl;
}
