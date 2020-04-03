/*
 * @Author: Hellcat
 * @Date: 2020-01-27 10:48:42
 */
#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
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

int bin[30005], dis[30005], num[30005]; // dis维护i到bin[i]之间的距离 num[]维护编号i所在那列有多少战舰

int find(int x) {
    if(bin[x] != x) {
        int root = bin[x];
        bin[x] = find(bin[x]);
        dis[x] += dis[root];
    }
    return bin[x];
}

void merge(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if(fx != fy) {
        bin[fx] = fy;
        dis[fx] += num[fy];
        num[fy] += num[fx];
        num[fx] = 1;
    }
}

int main() {
    int T;
    char c;
    int a, b;
    cin>>T;
    qwq(0,30001) { bin[i] = i; num[i] = 1; }
    while(T--) {
        cin>>c>>a>>b;
        if(c == 'M') merge(a,b);
        if(c == 'C') {
            if(find(a) != find(b)) puts("-1");
            else {
                cout<<(abs(dis[a] - dis[b])-1)<<endl;
            }
        }
    }
    return 0;
}