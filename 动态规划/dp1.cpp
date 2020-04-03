//HDU 1466 计算直线的交点数 经典
//分析:
// n = 1 ans = 0
// n = 2 ans = 0 1
// n = 3 ans = 0 2 3
//分组讨论: 假设一共有n = a + b条直线
//则总的交点数 = a内的交点数 + b内的交点数 + a,b之间的交点数
#include <bits/stdc++.h>
#define mes(a,b) memset(a,b,sizeof(a))
#define qwq(a,b) for(int i=a;i<b;++i)
#define qeq(a,b) for(int j=a;j<b;++j)
const long long mod=10;
typedef long long LL;
#define int long long
using namespace std;
bool dp[30][300] = {false};

void init(){
	for(int i = 1; i <= 20; i++){
		dp[i][0] = true;  //i条边有0个交点
	}
	for(int i = 1; i <= 20; i++){
		for(int j = 1; j <= i; j++){
			for(int k = 0; k <= 200; k++){
				if(dp[j][k]){ //j条边 k个交点的情况存在
					dp[i][(i-j)*j+k] = true;  //i条边 (i-j)条边平行
				}
			}
		}
	}
}

signed main(){
	int n;
	init();
	while(~scanf("%d", &n)){
		for(int i = 0; i <= n*(n-1)/2; i++){
			if(dp[n][i]){
				printf("%d%c",i, i == n*(n-1)/2 ? '\n':' ');
			}
		}
	}
}

//HDU 2084 数塔
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#define qwq(a, b) for(int i = a; i < b; i++)
#define qeq(a, b) for(int j = a; j < b; j++)
using namespace std;

int a[128][128], dp[128][128];
int n;

int solve(int i, int j){
	if(dp[i][j] >= 0) return dp[i][j];
	return dp[i][j] = a[i][j] + (i == n - 1 ? 0 : max(solve(i + 1, j),solve(i + 1, j + 1)));
}

int main ()
{
    int T;
    while(~scanf("%d", &T)){
        while(T--){

			scanf("%d", &n);
			qwq(0, n){
				qeq(0, i + 1) scanf("%d", &a[i][j]);
			}
			memset(dp, -1, sizeof(dp));
			for(int j = 0; j < n ; j++) dp[n][j] = a[n][j];
			cout<<solve(0, 0)<<endl;
        }
    }
}

//HDU 2084 数塔
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#define qwq(a, b) for(int i = a; i < b; i++)
#define qeq(a, b) for(int j = a; j < b; j++)
using namespace std;

int a[128][128], dp[128][128];

int main ()
{
    int T;
    while(~scanf("%d", &T)){
        while(T--){
        	int n;
			scanf("%d", &n);
			qwq(0, n){
				qeq(0, i + 1) scanf("%d", &a[i][j]);
			}
			memset(dp, 0, sizeof(dp));
			//for(int j = 0; j < n ; j++) dp[n][j] = a[n][j];
			for(int i = n - 1; i >= 0; i--)
				for(int j = 0; j <= i; j++){
					dp[i][j] = a[i][j] + max(dp[i+1][j],dp[i+1][j+1]);
					//cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
				}

        }
        cout<<dp[0][0]<<endl;
    }

}
