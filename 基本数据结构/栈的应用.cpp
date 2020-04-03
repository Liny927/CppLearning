/*
 * @Author: Hellcat
 * @Date: 2020-01-30 12:32:32
 * HDU 1062 栈应用 (模拟计算器)
 */
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
#define TIE cin.tie(0)
#define max(x,y) (x>y?x:y)
#define mes(a,b) memset(a,b,sizeof(a))
#define qwq(a,b) for(int i = (a); i < (b); ++i)
#define qeq(a,b) for(int j = (a); j < (b); ++j)
#define qsq(a,b) for(int s = (a); s < (b); ++s)
#define qaq(a,b) for(int k = (a); k > (b); --k)
using namespace std;

int main() {
    double n, m;
    char ch;
    while(~scanf("%lf", &n)) {
        ch = getchar();         // 吃空格
        if(ch == '\n' && n == 0) break;
        stack<double> s;
        while(s.size()) s.pop();  // 清空
        s.push(n);
        ch = getchar();
        while(~scanf("%lf", &n)) {
            if(ch == '*') {
                m = s.top();
                s.pop();
                m *= n;
                s.push(m);
            }
            if(ch == '/') {
                m = s.top();
                s.pop();
                m /= n;
                s.push(m);
            }
            if(ch == '+')
                s.push(n);
            if(ch == '-')
                s.push(- n);
            if(getchar() == '\n')
                break;
            ch = getchar();
        }
        double res = 0;
        while(s.size()) {
            res += s.top();
            s.pop();
        }
        printf("%.2f\n", res);
    }
}
