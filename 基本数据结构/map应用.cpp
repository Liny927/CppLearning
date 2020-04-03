/*
 * @Author: Hellcat
 * @Date: 2020-02-01 16:09:55
 * HDU 2684
 */
#include <bits/stdc++.h>
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
typedef pair<int,int> P;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    map<string,int> shop;
    while(cin>>n) {
        string s;
        int p;
        qwq(0,n)
            cin>>s;
        int m;
        cin>>m;
        while(m--) {
            qwq(0,n) {
                cin>>p>>s;
                shop[s] += p;
            }
            int rank = 1;
            map<string,int>::iterator it;
            for( it = shop.begin(); it != shop.end(); it++)
                if(it->second > shop["memory"])
                    rank++;
            cout<<rank<<endl;
        }
        shop.clear();
    }
}