/*
 * @Author: Hellcat
 * @Date: 2019-11-16 22:37:03
 */
#include <bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
#define N 100000
#define int long long
typedef long long LL;
typedef unsigned long long ULL;

//快速幂模板（取模）
//如pow(x,22)=pow(x,16)*pow(x,4)*pow(x,2),22十进制数为10110
LL mod_pow(LL x, LL n) {
	LL res = 1;
	while(n) {
		if(n & 1)//<=> n%2
			res = (res * x) % mod;
		x = (x * x) % mod; //将x平方
		n >>= 1;//<=> n/=2
	}
	return res;
}

LL mod_mul(LL a, LL b, LL mod) {
    LL res =  0;
    for(; b; b >>= 1) {
        if(b & 1) res = (res + a) % mod;
        a = a * 2 % mod;
    }
    return res;
}

//分治法
LL pow_mod(LL x, LL n, LL mod)
{
    if(n == 0) return 1;
    LL res = pow_mod(x * x % mod, n / 2, mod);
    if(n & 1) res = (res * x) % mod;
    return res;
}

//矩阵快速幂 Matrix_pow
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<LL> vec;
typedef vector<vec> mat;

const LL mod = 2147493647;

inline LL read() {
    char c = getchar(); LL n = 0;
    while (c < '0' || c > '9') { c = getchar(); }
    while (c >= '0' && c <= '9') { n = (n << 1) + (n << 3) + (c & 15); c = getchar(); }
    return n;
}

// 两个矩阵相乘
mat mul(mat &A, mat &B) {
    mat C(A.size(), vec(B[0].size()));
    for(LL i = 0; i < A.size(); i++)
        for(LL k = 0; k < B.size(); k++)
            for(LL j = 0; j <B[0].size(); j++) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
            }
    return C;
}

// 求A^n
mat pow(mat A, LL n) {
    mat B(A.size(), vec(A.size()));
    for(LL i = 0; i < A.size(); i++) {
        B[i][i] = 1;
    }
    while(n) {
        if(n & 1) B = mul(B, A);
        A = mul(A, A);
        n >>= 1;
    }
    return B;
}