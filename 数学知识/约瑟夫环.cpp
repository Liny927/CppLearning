#include <iostream>
#include <stdio.h>
#include <string.h>
#define N 1000010
#define mes(a,b) memset(a,b,sizeof(a))
#define qwq(a,b) for(int i=a; i<b; ++i)
#define qeq(a,b) for(int j=a; j<b; ++j)
typedef unsigned long long ULL;
using namespace std;

int cir(int n, int m) {
    int p = 0;
    for(int i = 2; i <= n; i++) {
        p = (p + m) % i;
    }
    return p + 1;
}

int main(){
    int n, m;
    int num[128];
    while(~scanf("%d%d", &n, &m)){
        int res = cir(n, m);
        printf("最后留下来的是：%d\n", res);
    }
    return 0;
}
