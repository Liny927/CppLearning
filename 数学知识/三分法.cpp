/*
 * @Author: Hellcat
 * @Date: 2020-01-20 19:41:27
 * HDU 2899
 */
#pragma GCC optime(2)
#include <iostream>
#include <string.h>
#include <string>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#include <ctype.h>
#include <algorithm>
#define max(x,y) (x>y?x:y)
#define mes(a,b) memset(a,b,sizeof(a))
#define max(x,y) (x>y?x:y)
#define mes(a,b) memset(a,b,sizeof(a))
#define qwq(a,b) for(int i = (a); i < (b); ++i)
#define qeq(a,b) for(int j = (a); j < (b); ++j)
#define qaq(a,b) for(int k = (a); k > (b); --k)
const double esp = 1e-6;
typedef long long LL;
typedef unsigned long long ULL;
using namespace std;
double Y;
double f(double x) {
    return 6 * pow(x, 7) + 8 * pow(x, 6) + 7 * pow(x, 3) + 5 * pow(x,2) - Y * x;
}

int main() {
    int T;
    cin>>T;
    while(T--) {
        scanf("%lf", &Y);
        double a = 0, b = 100, x, y;
        while(b - a > esp) {
            x = a + (b - a) / 3;
            y = a + (b - a) /3 * 2;
            if( f(x) > f(y))
                a = x;
            else
                b = y;
        }
        printf("%.4f\n", f(a));
    }
}
