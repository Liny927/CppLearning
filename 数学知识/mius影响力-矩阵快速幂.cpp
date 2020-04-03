/*
 * @Author: Hellcat
 * @Date: 2020-03-27 19:57:26
 * https://ac.nowcoder.com/discuss/364600?type=101&order=0&pos=1&page=3
 */
#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

typedef long long LL;
typedef vector<LL> vec;
typedef vector<vec> mat;

const LL mod = 1e9 + 7;

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
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % (mod - 1);
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

LL mod_pow(LL x, LL n) {
    LL res = 1;
    while(n) {
        if(n & 1)
            res = (res * x) % mod;
        x = (x * x) % mod;
        n >>= 1;
    }
    return res;
}

int main() {
    LL n, x, y, a, b;
    scanf("%lld%lld%lld%lld%lld", &n, &x, &y, &a, &b);
    if(n == 1) { printf("%lld\n",x % mod); return 0; }
    else if(n == 2) { printf("%lld\n",y % mod); return 0; }
    a = mod_pow(a%mod,b);
    x %= mod;
    y %= mod;
    mat A(2, vec(2));
    mat F(2, vec(1));
    mat G(2, vec(2));
    mat D(2, vec(1));
    mat P(3, vec(3));
    mat E(3, vec(1));
    A[0][0] = 0, A[0][1] = 1;
    A[1][0] = 1, A[1][1] = 1;
    A = pow(A,n - 1);
    F[0][0] = 1;
    F[1][0] = 0;
    A = mul(A,F);
    LL xx = A[0][0];
    G[0][0] = 0, G[0][1] = 1;
    G[1][0] = 1, G[1][1] = 1;
    G = pow(G,n - 1);
    D[0][0] = 0;
    D[1][0] = 1;
    G = mul(G,D);
    LL yy = G[0][0];
    P[0][0] = 0, P[0][1] = 1, P[0][2] = 0;
    P[1][0] = 1, P[1][1] = 1, P[1][2] = 1;
    P[2][0] = 0, P[2][1] = 0, P[2][2] = 1;
    P = pow(P,n - 1);
    E[0][0] = 0;
    E[1][0] = 0;
    E[2][0] = 1;
    P = mul(P,E);
    LL aa = P[0][0];
    // cout<<xx<<' '<<yy<<' '<<aa<<endl;
    if(x % mod == 0 || y % mod == 0 || a % mod == 0) return puts("0"), 0;
    printf("%lld\n", mod_pow(x,xx) * mod_pow(y,yy) % mod * mod_pow(a,aa) % mod);
}