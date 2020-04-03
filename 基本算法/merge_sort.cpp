/*
 * @Author: Hellcat
 * @Date: 2020-01-15 10:32:07
 */
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

void merge_sort(int *A, int x, int y, int *T) {
    if(y-x > 1) {
        int m = x + (y-x)/2;
        int p = x, q = m, i = x;
        merge_sort(A, x, m, T);
        merge_sort(A, m, y, T);
        while(p < m || q < y) {
            if(q >= y || (p < m && A[p] >= A[q])) T[i++] = A[p++]; //��������鸴�Ƶ���ʱ�ռ�
            else T[i++] = A[q++];  //���Ұ����鸴�Ƶ���ʱ�ռ�
        }
        for(i = x; i < y; i++) A[i] = T[i]; //����ʱ�ռ临�ƻ�A����
    }
}

int main() {
    int A[] = {10, 8, 8, 7, 16, -2, 4};
    int T[128];
    merge_sort(A,0,7,T);
    qwq(0,7)
    cout<<A[i]<<" "<<endl;
}