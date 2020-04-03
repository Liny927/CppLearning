/*
 * @Author: Hellcat
 * @Date: 2020-01-06 18:41:56
 * n皇后 0数组起点
 */
#include <bits/stdc++.h>
#define qwq(a,b) for(int i = a; i < b; i++)
#define qeq(a,b) for(int j = a; j < b; j++)
#define mes(a,b) memset(a,0,sizeof(a))
typedef long long LL;
using namespace std;

int ans = 0, n = 0;
int a[128];

//fa, fb, fc分别记录 列 主 副对角线
//fc搜索时 +15 是为了避免出现负数
bool fa[100], fb[100], fc[100];
void print() {
	ans++;
	if(ans <= 3) {
		for(int i = 0; i < n - 1; i++)
			cout<<a[i]<<' ';
		cout<<a[n-1]<<endl;
	}
}

void dfs(int i) {
	if(i == n) print();
	else {
		for(int j = 0; j < n; j++) {
			if((!fa[j]) && (!fb[j + i]) && (!fc[i - j + 15])) {
				fa[j] = 1;
				fb[j + i] = 1;
				fc[i - j + 15] = 1;
				a[i] = j + 1;
				dfs(i + 1);
				fa[j] = 0;
				fb[j + i] = 0;
				fc[i - j + 15] = 0;
			}
		}
	}
}

int main() {
	mes(fa,0);
	mes(fb,0);
	mes(fc,0);
	cin>>n;
	dfs(0);
	cout<<ans;
}