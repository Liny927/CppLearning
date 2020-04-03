/*
 * @Author: Hellcat
 * @Date: 2019-11-30 10:44:28
 */
#include <bits/stdc++.h>
using namespace std;

//i为全局变量
int i;

//只要检查 2~√n 的所有整数即可 O(√n)
bool is_prime1(int n){
	if(n <= 1) return false;
	int m = floor(sqrt(n) + 0.5);  //小数部分处理
	for(int i = 2; i <= m; i++)
		if(!(n % i)) return false;
	return true;
}

//写法二
bool is_prime2(int n){
	for(i = 2; i * i <= n; i++){
		if(!(n % i)) return false;
	}
	return n != 1;//1是例外
}

//约数枚举O(√n)
vector<int> divisor(int n){
	vector<int> res;
	for(i = 1; i * i <= n; i++){
		if(n % i == 0){
			res.push_back(i);
			if(i != n / i) res.push_back(n / i);
		}
	}
	return res;
}

//整数分解O(√n)
map<int,int> prime_factor(int n){
	map<int,int>res;
	for(int i = 2; i * i <= n; i++){
		while(n % i == 0){
			++res[i];
			n /= i;
		}
	}
	if (n != 1) res[n] = 1;
	return res;
}

//埃氏筛法 类似于辗转相除法的古老算法
//用于对许多整数进行素性测试 返回n以内的素数个数
int prime[MAX_N]; //第i个素数
bool is_prime[MAX_N + 1];
int solve(int n) {
	int p = 0;
	for(int i = 0; i <= n; i++) is_prime[i] = true;
	is_prime[0] = is_prime[1] = false;
	for(int i = 2; i <= n; i++) {
		if(is_prime[i]) {
			prime[p++] = i;
			for(int j = 2 * i; j <= n; j += i) is_prime[j] = false;
		}
	}
	return p;
}



//区间筛法 求区间内的素数个数
typedef long long ll;

bool is_prime[MAX_L];
bool is_prime_small[MAX_SQRT_B];

//对区间[a, b)内的整数执行筛法 is_prime[i-a] = true <=> i是素数
void segment_sieve(ll a, ll b) {
	for(int i = 0; (ll)i * i < b; i++) is_prime_small[i] = true;
	for(int i = 0; i < b - a; i++) is_prime[i] = true;

	for(int i = 2; (ll)i * i < b; i++) {
		if(is_prime_small[i]) {
			for(int j = 2 * i; (ll)j * j < b; j += i) is_prime_small[j] = false; //筛选[2, √b)
			for(ll j = max(2LL, (a + i - 1) / i) * i; j < b; j += i) is_prime[j - a] = false; //筛选[a, b)

		}
	}
}


//bool素数筛
bool notprime[MAXN];//数组只有二值 false表示素数 true表示素数
void init(void){
	mes(notprime,false);
	notprime[0] = notprime[1] = true;
	qwq(2,MAXN)
		if(!notprime[i]){
			if(i > MAXN/i) continue;
			for(int j = i * i; j < MAXN; j += i)
				notprime[j] = true;
		}
}
