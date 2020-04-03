/*
 * @Author: Hellcat
 * @Date: 2019-12-23 20:01:34
 *
 */

#pragma GCC optime(2)
#include <iostream>
#include <string.h>
#include <string>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <ctype.h>
#include <algorithm>
#define max(x,y) (x>y?x:y)
#define mes(a,b) memset(a,b,sizeof(a))
#define max(x,y) (x>y?x:y)
#define mes(a,b) memset(a,b,sizeof(a))
#define qwq(a,b) for(int i = (a); i < (b); ++i)
#define qeq(a,b) for(int j = (a); j < (b); ++j)
#define qaq(a,b) for(int k = (a); k > (b); --k)
typedef long long LL;
typedef unsigned long long ULL;
using namespace std;

char maze[12][12];
bool vis[10];  //��¼�������ӵ���
int fx[20], fy[20];
int to[4][2] = {
    {0, -1}, {0, 1}, {1, 0}, {-1, 0},
};
int res = 0;
int n, k;
int cnt = 0;
void dfs(int cur) {
	if(cur == k) { res++; return; }
	if(cur > n) return;
	qwq(1,n + 1) {     //��������
		if(!vis[i] && maze[cur][i] == '#') {
			vis[i] = 1;
			cnt++;
			dfs(cur + 1);  //�ڷ�������ӵ�����½�����һ��
			vis[i] = 0;
			cnt--;        //����
		}
	}
	dfs(cur + 1); //���з���
}

int main() {
	while(cin>>n>>k) {
		if(n == -1 && k == -1) return 0;
		res = 0;
		cnt = 0;
		qwq(1,n + 1)
			cin>>maze[i] + 1;
		//mes(fx,0);
		//mes(fy,0);
		mes(vis,0);
		dfs(1);
		cout<<res<<endl;
	}
}
