/*
 * @Author: Hellcat
 * @Date: 2020-01-26 17:46:32
 * POJ 2236
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

int bin[10002];
int a[10002];  // 记录修好的电脑编号
int n, d, x[10002], y[10002], p1, p2;
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

double distance(int a, int b) {
    return sqrt((double)((x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b])));
}

int main() {
    char ch;
    int cnt = 0;
    mes(a,0);
    scanf("%d%d", &n, &d);
    qwq(1,n + 1)    // 初始化并查集
        bin[i] = i;
    qwq(1,n + 1) {
        scanf("%d%d", &x[i], &y[i]);
    }
    while(~scanf("%c", &ch)) {
        if(ch == 'O') {
            scanf("%d", &p1);
            a[cnt++] = p1;
            qwq(0,cnt) {
                if(distance(a[i],p1) <= (double)d) {
                    merge(p1,a[i]);
                    //cout<<"TEST::"<<p1<<' '<<a[i]<<endl;
                }
            }
        }
        if(ch == 'S') {
            scanf("%d%d", &p1, &p2);
            if(findx(p1) == findx(p2)) cout<<"SUCCESS"<<endl;
            else cout<<"FAIL"<<endl;
        }
    }
}