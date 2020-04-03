/*
 * @Author: Hellcat
 * @Date: 2020-01-28 16:58:31
 * P1962 斐波那契数列 矩阵加速
 */
#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#define qaq(a,b) for(int k = (a); k > (b); --k)
#define INF 0x3f3f3f3f
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<LL> vec;
typedef vector<vec> mat;

const LL mod = 10000;

inline LL read() {
    LL x = 0 , f = 1 ; char c = getchar() ;
    while( c < '0' || c > '9' ) { if( c == '-' ) f = -1 ; c = getchar() ; }
    while( c >= '0' && c <= '9' ) { x = x * 10 + c - '0' ; c = getchar() ; }
    return x * f ;
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

int main() {
    LL n;
    while(1) {
        n = read();
        if(n == -1) break;
        mat A(2, vec(2));
        A[0][0] = A[0][1] = A[1][0] = 1;
        A[1][1] = 0;
        A = pow(A, n);
        cout<<A[1][0]<<endl;
    }
}
