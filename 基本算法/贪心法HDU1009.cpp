//HDU1009 贪心法
#include <bits\stdc++.h>
#define mes(a, b) memset(a,b,sizeof(a))
#define qwq(a, b) for(int i = a; i < b; ++i)
#define qeq(a, b) for(int j = a; j < b; ++j)
using namespace std;

typedef struct food{
	double j;
	double f;
	double c;   //性价比
}FOD;

bool cmp(food a, food b){
	return a.c > b.c;  //性价比从高到低
}

int main(){
	FOD fod[1280];
	int m, n;
	while(~scanf("%d %d",&m, &n)){
		double res = 0;
		if(m == -1 && n == -1) return 0;
		//特判
		if(n == 0) {
			puts("0.000");
			continue;
		}
		qwq(0, n) {
			scanf("%lf %lf", &fod[i].j, &fod[i].f);
			if(fod[i].f == 0) {
				res += fod[i].j;
				fod[i].c = 0;
			}
			else fod[i].c = fod[i].j / fod[i].f;
		}
		sort(fod, fod + n, cmp);
		int i = 0;
		while(m){
			if(m > fod[i].f) {
				res += fod[i].j;
				m -= fod[i].f;
			}
			else {
				res += m/fod[i].f * fod[i].j;
				m = 0;
			}
			i++;
		}
		printf("%.3f\n", res);
	}
}