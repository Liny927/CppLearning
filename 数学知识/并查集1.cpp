/*
 * @Author: Hellcat
 * @Date: 2020-01-24 15:40:24
 * HDU 1232
 */
#include <bits/stdc++.h>
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

int bin[1002];
// 非递归版本
// int findx(int x) { // 查询树的根
//   while(bin[x] != x)
//     x = bin[x] = bin[bin[x]];
//   return x;
// }

// 递归版本
int findx(int x) { // 带路径压缩
  if(bin[x] == x) return x;
  return bin[x] = findx(bin[x]);
}

// int findx(int x)
// {
//     int r=x;
//     while(bin[r] !=r)
//         r=bin[r];
//     return r;
// }

void merge(int x, int y) {  // 合并x和y所属的集合
  int fx, fy;
  fx = findx(x);
  fy = findx(y);
  if(fx != fy)
    bin[fx] = fy;
}

int main() {
  int n, m, x, y;
  while(scanf("%d", &n) , n) {
    qwq(1,n+1)
      bin[i] = i;
    for(scanf("%d", &m); m>0; m--) {
      cin>>x>>y;
      merge(x,y);
    }
    int cnt, i;
    for(cnt = -1, i = 1; i <= n; i++)
      if(bin[i] == i)
        cnt++;
    cout<<cnt<<endl;
  }
}

/*
 * HDU 1232 畅通工程
 * 并查集
 */
#include <iostream>
using namespace std;

const int SIZE = 1005;
int root[SIZE];
int rank[SIZE];

int find(int x) {
	int y = x;
	while (root[y] != y) {
		y = root[y];
	}

	int temp, head = y;
	y = x;
	while (root[y] != y) {
		temp = root[y];
		root[y] = head;
		y = temp;
	}

	return head;
};

void UNION(int x, int y) {
	int f1 = find(x);
	int f2 = find(y);

	if (rank[f1] <= rank[f2]) {
		root[f1] = f2;
		if (rank[f1] == rank[f2]) {
			rank[f2] ++;
		}
	} else {
		root[f2] = f1;
	}
};

int main()
{
	int N, M, s, e, count;

	while (scanf("%d%d",&N,&M)!=EOF, N) {
		for (int i = 1; i <= N; ++ i)
			root[i] = i;

		for (int i = 0; i < M; ++ i) {
			scanf("%d%d",&s,&e);
			UNION(s,e);
		}

		count = -1;
		for (int i = 1; i <= N; ++ i) {
			if (root[i] == i)
				++ count;
		}

		printf("%d\n",count);
	}
}