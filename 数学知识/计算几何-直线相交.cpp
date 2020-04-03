/*
 * @Author: Hellcat
 * @Date: 2020-01-30 11:06:20
 */
#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#pragma GCC optimize(2)
#define IOS ios::sync_with_stdio(false)
#define TIE cin.tie(0)
#define max(x,y) (x>y?x:y)
#define mes(a,b) memset(a,b,sizeof(a))
#define max(x,y) (x>y?x:y)
#define mes(a,b) memset(a,b,sizeof(a))
#define qwq(a,b) for(int i = (a); i < (b); ++i)
#define qeq(a,b) for(int j = (a); j < (b); ++j)
#define qsq(a,b) for(int s = (a); s < (b); ++s)
#define qaq(a,b) for(int k = (a); k > (b); --k)
#define INF 0x3f3f3f3f
typedef long long LL;
using namespace std;

const double EPS = 1e-10;
int bin[10010];

double add(double a, double b) {
    if(abs(a + b) < EPS * (abs(a) + abs(b))) return 0;
    return a + b;
}

struct P {
    double x, y;
    P() {}
    P(double x, double y) : x(x), y(y) {}
    P operator + (P p) { return P(add(x, p.x), add(y, p.y)); }
    P operator - (P p) { return P(add(x, -p.x), add(y, -p.y)); }
    P operator * (double d) { return P(x *d, y * d); }
    double dot(P p) { // 内积
        return add(x * p.x, y * p.y);
    }
    double det(P p) { // 外积
        return add(x * p.y, -y * p.x);
    }
};

// 判断点q是否在线段p1-p2上
bool on_seg(P p1, P p2, P q) {
    return (p1 - q).det(p2 - q) == 0 && (p1 - q).dot(p2 - q) <= 0;
}

// 计算直线p1-p2与直线q1-q2的交点
P intersection(P p1, P p2, P q1, P q2) {
    return p1 + (p2 - p1) * ((q2 - q1).det(q1 - p1) / (q2 - q1).det(p2 - p1));
}

int findx(int x) { // 带路径压缩
    return bin[x] == x ? x : bin[x] = findx(bin[x]);
}

void merge(int x, int y) {  // 合并x和y所属的集合
  int fx, fy;
  fx = findx(x);
  fy = findx(y);
  if(fx != fy)
    bin[fx] = fy;
}

bool same(int x, int y) {
    return findx(x) == findx(y);
}