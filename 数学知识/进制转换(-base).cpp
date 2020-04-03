#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <set>
#include <stdlib.h>
#include <cctype>
#define qwq(a,b) for(int i = a; i < b; i++)
#define qeq(a,b) for(int j = a; j < b; j++)
#define mes(a,b) memset(a,0,sizeof(a))
typedef long long LL;
using namespace std;

char s[1010] = {'\0'};
char a[1010] = {'\0'};
int num = 0;

//（商+1）*除数+（余数-除数）=商*除数+除数+余数-除数=商*除数+余数=被除数
void convert(int x, int base) {
	do {
		int k = x % base;
		if(k < 0)
			//余数减除数  商加1
			k -= base,   x += base;
		if(k >= 10) s[num++] = k + 'A' - 10;
		else s[num++] = k + '0';
		x /= base;
	} while(x);
}

int main() {
	int x, base;
	scanf("%d %d", &x, &base);
	convert(x, base);
	int j = 0;
	for(int i = num - 1; i >= 0; i--) {
		a[j++] = s[i];
	}
	printf("%d=%s(base%d)", x, a, base);
}