/*
 * @Author: Hellcat
 * @Date: 2020-01-28 16:58:31
 * HDU 5950
 */
#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#pragma GCC optimize(2)
#define IOS ios::sync_with_stdio(false)
#define TIE cin.tie(0)
#define max(x,y) (x>y?x:y)
#define mes(a,b) memset(a,b,sizeof(a))
#define qwq(a,b) for(int i = (a); i < (b); ++i)
#define qeq(a,b) for(int j = (a); j < (b); ++j)
#define qsq(a,b) for(int s = (a); s < (b); ++s)
#define qaq(a,b) for(int k = (a); k > (b); --k)
#define INF 0x3f3f3f3f
using namespace std;

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

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        LL n, a, b;
        n = read();
        a = read();
        b = read();
        mat A(7, vec(7));
        mat D(7, vec(1));
        A[0][0] = 1, A[0][1] = 0, A[0][2] = 0, A[0][3] = 0, A[0][4] = 0, A[0][5] = 0, A[0][6] = 0;
        A[1][0] = 1, A[1][1] = 1, A[1][2] = 0, A[1][3] = 0, A[1][4] = 0, A[1][5] = 0, A[1][6] = 0;
        A[2][0] = 1, A[2][1] = 2, A[2][2] = 1, A[2][3] = 0, A[2][4] = 0, A[2][5] = 0, A[2][6] = 0;
        A[3][0] = 1, A[3][1] = 3, A[3][2] = 3, A[3][3] = 1, A[3][4] = 0, A[3][5] = 0, A[3][6] = 0;
        A[4][0] = 1, A[4][1] = 4, A[4][2] = 6, A[4][3] = 4, A[4][4] = 1, A[4][5] = 0, A[4][6] = 0;
        A[5][0] = 0, A[5][1] = 0, A[5][2] = 0, A[5][3] = 0, A[5][4] = 1, A[5][5] = 1, A[5][6] = 2,
        A[6][0] = 0, A[6][1] = 0, A[6][2] = 0, A[6][3] = 0, A[6][4] = 0, A[6][5] = 1, A[6][6] = 0;
        D[0][0] = 1;
        D[1][0] = 3;
        D[2][0] = 9;
        D[3][0] = 27;
        D[4][0] = 81;
        D[5][0] = b;
        D[6][0] = a;
        if(n == 1) { cout<<a<<endl; continue; }
        if(n == 2) { cout<<b<<endl; continue; }
        A = pow(A, n-1);
        A = mul(A, D);
        cout<<A[6][0]<<endl;
    }
}
