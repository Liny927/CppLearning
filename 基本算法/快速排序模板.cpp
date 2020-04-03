/*
 * @Author: Hellcat
 * @Date: 2020-01-13 15:15:37
 */
#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <set>
#define qwq(a,b) for(int i = a; i < b; i++)
#define mes(a,b) memset(a,0,sizeof(a))
using namespace std;

int Partition(int A[], int left, int right) {
	int temp = A[left];
	while(left < right) {
		while(left < right && A[right] > temp)
			right--;
		A[left] = A[right];
		while(left < right && A[left] <= temp)
			left++;
		A[right] = A[left];
	}
	A[left] = temp;
	return left;
}

//快速排序运用了二分的思想
void quickSort(int arr[], int left, int right){
    int i = left, j = right;
    int mid = arr[(i+j)/2];
    while(i <= j){
        while(arr[i] < mid) i++;
        while(arr[j] > mid) j--;
        if(i <= j){
            int tmp;
            tmp = arr[i]; arr[i] = arr[j]; arr[j] = tmp;
            i++; j--;
        }
    }
    if(i < right) quickSort(arr,i, right);
    if(left < j) quickSort(arr,left, j);
}

int main() {
	int arr[100010];
	int n;
	scanf("%d", &n);
	qwq(0,n)
        scanf("%d", &arr[i]);
	quickSort(arr, 0, n-1);
	qwq(0,n)
		printf("%d%c", arr[i], i == n - 1 ? '\n' : ' ');
}