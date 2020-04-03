//HDU 1005 大数据找规律
#include <bits/stdc++.h>
#define mes(a,b) memset(a,b,sizeof(a))
#define qwq(a,b) for(int i=a;i<b;++i)
#define qeq(a,b) for(int j=a;j<b;++j)
const long long mod=10;
typedef long long LL;
using namespace std;

signed main(){
	int a, b, n;
	//以下部分运算用于寻找规律
	// int f[12800];
	// f[1] = 1;
	// f[2] = 1;
	// for(int i = 3; i < 200; i++){
	// 	f[i] = (3 * f[i-1] + 6 * f[i-2]) % 7;
	// 	printf("%d ", f[i]);
	// }
	//对于1 1//2 3 5 1 6 0 6 6 5 4 2 6 1 0 1 1	//16个数一循环
	//对于1 2//3 5 4 0 1 1         				//6个数一循环
	//对于3 2//5 3 5 0 3 2 5 5 4 1 4 0 1 3 4 4 6 5 6 0 5 1 6 6 2 4 2 0 4 5 2 2 3 6 3 0 6 4 3 3 1 2 1 0 2 6 1 1  //48个数一循环
	//对于3 5//1 1 1 1 1 1 1 1 1 1 1           //周期为1
	//   3 6//2 5 6 6 5 2 1 1 2 5 6 6 5 2 1 1  //16
	while(~scanf("%d %d %d", &a, &b, &n)){
		if(!a && !b && !n) return 0;
		n = n % 48;
		int f[1280];
		f[1] = 1;
		f[2] = 1;
		for(int i = 3; i < 49; i++)
			f[i] = (a * f[i-1] + b * f[i-2]) % 7;
		cout<<f[n]<<endl;
	}
}
