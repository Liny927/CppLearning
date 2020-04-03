/*
 * @Author: Hellcat
 * @Date: 2020-01-25 19:34:38
 * HDU 1272
 */
#include <cstdio>
#include <algorithm>
#include <cstring>
#define max(x,y) (x>y?x:y)
#define mes(a,b) memset(a,b,sizeof(a))
#define qwq(a,b) for(int i = (a); i < (b); ++i)
#define qeq(a,b) for(int j = (a); j < (b); ++j)
#define qsq(a,b) for(int s = (a); s < (b); ++s)
#define qaq(a,b) for(int k = (a); k > (b); --k)
using namespace std;

int bin[100010];

int find(int x) {
    return bin[x] == x ? x : bin[x] = find(bin[x]);
}

void merge(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if(fx != fy)
        bin[fx] = fy;
}

int main()
{
	int a, b, flag, i, sum, cnt = 0;
	while(1)
	{
        cnt++;
        mes(bin,0);
		flag = 0;
		while(~scanf("%d%d",&a,&b) && a != 0 && b != 0) {
            if(a == -1 && b == -1) return 0;
            if(bin[a] == 0) bin[a] = a;
            if(bin[b] == 0) bin[b] = b;
            if(find(a) == find(b)) flag = 1;
            else if(!flag)
            merge(a,b);
        }
        for(sum = 0, i = 1; i <= 100000; i++)
        {
            if(bin[i] == i) sum++;
            bin[i] = 0;
        }
        if(sum > 1 || flag)
        printf("No\n");
        else
        printf("Yes\n");
	}
}
