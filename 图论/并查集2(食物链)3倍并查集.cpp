/*
 * @Author: Hellcat
 * @Date: 2020-01-24 16:07:07
 * 食物链 3倍并查集
 */
#include <iostream>
#include <cstdio>
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
const int maxn = 1e5 + 10;

inline int read() {
    char c = getchar(); int n = 0;
    while (c < '0' || c > '9') { c = getchar(); }
    while (c >= '0' && c <= '9') { n = (n << 1) + (n << 3) + (c & 15); c = getchar(); }
    return n;
}

// 对于每只动物i创建3个元素i-A, i-B, i-C 并对这3xN个元素建立并查集
// x, x + N, x + 2*N 分别代表x-A, x-B, x-C (1倍本身 2倍猎物 3倍天敌)
int bin[3*maxn+5];
int findx(int x) { // 查询树的根
  while(bin[x] != x)
    x = bin[x] = bin[bin[x]];
  return x;
}

void merge(int x, int y) {  // 合并x和y所属的集合
  int fx, fy;
  fx = findx(x);
  fy = findx(y);
  if(fx != fy)
    bin[fx] = fy;
}

bool same(int x, int y) { // 判断x y是否属于同一个集合
  return findx(x) == findx(y);
}

int main() {
  int n, k, ans = 0;
  n = read(); k = read();
  qwq(1,3*n+1) bin[i] = i;
  qwq(1,k+1) {
    int d, x, y;
    d = read(), x = read(), y = read();
    if(x <= 0 || x > n || y <= 0 || y > n) { ans++; continue; } // 编号错误
    if(d == 1) { // 同类
      if(same(x + n, y) || same(x + 2 * n, y))  ans++;
      else {
        merge(x, y);
        merge(x + n, y + n);
        merge(x + 2 * n, y + 2 * n);
      }
    }
    else { // 捕食关系
      if(same(x, y) || same(x + 2 * n, y))  ans++;
      else {
        merge(x, y + 2 * n);
        merge(x + n, y);
        merge(x + 2 * n, y + n);
      }
    }
  }
  cout<<ans<<endl;
}
