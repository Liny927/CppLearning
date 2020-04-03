//静态表打表法 核心：找到规律
// 我们看一下n= (0 - 99),的结果：

// 0 1 4 7 6 5 6 3 6 9
// 0 1 6 3 6 5 6 7 4 9

// 0 1 4 7 6 5 6 3 6 9
// 0 1 6 3 6 5 6 7 4 9

// 0 1 4 7 6 5 6 3 6 9
// 0 1 6 3 6 5 6 7 4 9

// 0 1 4 7 6 5 6 3 6 9
// 0 1 6 3 6 5 6 7 4 9

// 0 1 4 7 6 5 6 3 6 9
// 0 1 6 3 6 5 6 7 4 9

#include <bits/stdc++.h>
#define mes(a,b) memset(a,b,sizeof(a))
#define qwq(a,b) for(int i=a;i<b;++i)
#define qeq(a,b) for(int j=a;j<b;++j)
const long long mod=10;
typedef long long LL;
using namespace std;


signed main(){
	//分析后找到规律
	// LL fib[1000];
	// fib[0] = 7;
	// fib[1] = 11;
	// for(int i = 2; i < 300; i++)
	// 	fib[i] = fib[i - 1] + fib[i - 2];
	// for(int i = 0; i < 200; i++)
	// 	if(fib[i]%3 == 0) printf(" %lld",i);

	LL n;
	while(scanf("%lld", &n)!=EOF){
		if((n - 2)%4 == 0) cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
}

