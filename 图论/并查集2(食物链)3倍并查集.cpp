/*
 * @Author: Hellcat
 * @Date: 2020-01-24 16:07:07
 * ʳ���� 3�����鼯
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

// ����ÿֻ����i����3��Ԫ��i-A, i-B, i-C ������3xN��Ԫ�ؽ������鼯
// x, x + N, x + 2*N �ֱ����x-A, x-B, x-C (1������ 2������ 3�����)
int bin[3*maxn+5];
int findx(int x) { // ��ѯ���ĸ�
  while(bin[x] != x)
    x = bin[x] = bin[bin[x]];
  return x;
}

void merge(int x, int y) {  // �ϲ�x��y�����ļ���
  int fx, fy;
  fx = findx(x);
  fy = findx(y);
  if(fx != fy)
    bin[fx] = fy;
}

bool same(int x, int y) { // �ж�x y�Ƿ�����ͬһ������
  return findx(x) == findx(y);
}

int main() {
  int n, k, ans = 0;
  n = read(); k = read();
  qwq(1,3*n+1) bin[i] = i;
  qwq(1,k+1) {
    int d, x, y;
    d = read(), x = read(), y = read();
    if(x <= 0 || x > n || y <= 0 || y > n) { ans++; continue; } // ��Ŵ���
    if(d == 1) { // ͬ��
      if(same(x + n, y) || same(x + 2 * n, y))  ans++;
      else {
        merge(x, y);
        merge(x + n, y + n);
        merge(x + 2 * n, y + 2 * n);
      }
    }
    else { // ��ʳ��ϵ
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
