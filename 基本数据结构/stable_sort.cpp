/*
 * @Author: hellcat
 * @Date: 2019-12-15 22:45:45
 */
#pragma GCC optimize(2)
#include <iostream>
#include <string.h>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define mes(a,b) memset(a, b, sizeof(a))
#define qwq(a,b) for(int i=a; i<b; ++i)
#define qeq(a,b) for(int j=a; j<b; ++j)
typedef long long LL;

typedef struct ranklist{
	int num;
	int score;
	int power;
}ranks;
ranks ran[200001], T[200001];

bool cmp(ranklist a, ranklist b) {
	if(a.score != b.score)
		return a.score > b.score;
	else
		return a.num < b.num;
}

void merge_sort(ranklist *A, int x, int y, ranklist *T) {
    if(y-x > 1) {
        int m = x + (y-x)/2;
        int p = x, q = m, i = x;
        merge_sort(A, x, m, T);
        merge_sort(A, m, y, T);
        while(p < m || q < y) {
            if(q >= y || (p < m && cmp(A[p],A[q]))) T[i++] = A[p++]; //从左半数组复制到临时空间
            else T[i++] = A[q++];  //从右半数组复制到临时空间
        }
        for(i = x; i < y; i++) A[i] = T[i]; //从临时空间复制回A数组
    }
}

int main(){
	int n, r, q;
	scanf("%d %d %d", &n, &r, &q);
	//输入初始分数值并编号
	qwq(1,2 * n + 1) {
		ran[i].num = i ;
		scanf("%d", &ran[i].score);
	}

	//输入实力值
	qwq(1,2 * n + 1)
		scanf("%d", &ran[i].power);
	sort(ran + 1, ran + 2 * n + 1, cmp);
	qwq(0,r) {
		//sort(ran + 1, ran + 2 * n + 1, cmp);  //快速排序每次全部修改 会造成浪费 导致TLE
		for(int j = 1; j <= 2*n; j += 2) {
			if(ran[j].power > ran[j + 1].power)
				ran[j].score++;
			else ran[j + 1].score++;
		}
		//stable_sort为归并排序 是稳定的
		stable_sort(ran + 1, ran + 2 * n + 1, cmp);
	}

	//qwq(1,2 * n + 1)
	cout<<ran[q].num;
}
