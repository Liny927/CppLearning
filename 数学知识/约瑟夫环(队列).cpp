/*
 * @Author: Hellcat
 * @Date: 2020-01-27 16:28:30
 */
#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#define IOS ios::sync_with_stdio(false)
#define TIE cin.tie(0)
#define max(x,y) (x>y?x:y)
#define mes(a,b) memset(a,b,sizeof(a))
#define max(x,y) (x>y?x:y)
#define mes(a,b) memset(a,b,sizeof(a))
#define qwq(a,b) for(int i = (a); i < (b); ++i)
#define qeq(a,b) for(int j = (a); j < (b); ++j)
#define qsq(a,b) for(int s = (a); s < (b); ++s)
#define qaq(a,b) for(int k = (a); k > (b); --k)
typedef long long LL;
typedef unsigned long long ULL;
using namespace std;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int x = 1;
    queue<int> q;
    for(int i = 1; i <= n; i++)
        q.push(i);
    while(q.size()) {
        if(x == m) {
            printf("%d ", q.front());
            q.pop();
            x = 1;
        }
        else {
            x++;
            q.push(q.front()); // ÅÅÖÁ¶ÓÎ²,Ñ­»·
            q.pop();
        }
    }
    putchar('\n');
}