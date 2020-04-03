/*
 * @Author: Hellcat
 * @Date: 2020-01-26 23:23:22
 */
#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
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
typedef long long LL;
typedef unsigned long long ULL;
using namespace std;

int bin[100002];

int n, m;
// 递归版本
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

struct node{
    int x;
    int y;
    int t;
}N[100010];

bool cmp(node a, node b) {
    return a.t < b.t;
}

int main() {
    int num = 0;
    scanf("%d%d", &n, &m);
    qwq(1,n+1) bin[i] = i;
    qwq(0,m) {
        scanf("%d%d%d", &N[i].x, &N[i].y, &N[i].t);
    }
    sort(N, N + m, cmp);
    merge(N[0].x, N[0].y);
    int res = N[0].t;
    num++;
    qwq(1,m) {
        if(findx(N[i].x) != findx(N[i].y)) {
            num++;
            res = max(res, N[i].t);
            merge(N[i].x, N[i].y);
        }
    }
    if(num >= n - 1) cout<<res<<endl;
    else cout<<"-1"<<endl;
}
