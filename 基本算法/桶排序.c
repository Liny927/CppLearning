#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//桶排序(基数排序)
//桶排序的桶其实是一组指向指针的指针 桶本身也是结构体
int main(){
	int a[]={2, 32, 23, 342, 343, 34, 43, 348, 835, 987};
	int* a_p = a;
	int size = sizeof(a)/sizeof(int);
	bucketSort(a_p, size);
    for(int i = 0; i < size; i++)
        printf("%d\n", a[i]);
}

void bucketSort(int *p, int n){
	int maxNum = findMaxNum(p, n); //获取数组中的最大数
	int loopTimes = getLoopTimes(maxNum); //获取最大的位数
	for(int i = 1; i <= loopTimes; i++)
	{
		sort2(p, n, i);
	}
}

//获取数字的位数
int getLoopTimes(int num){
	int cnt = 1;
	int temp = num/10;
	while(temp != 0){
		cnt++;
		temp = temp/10;
	}
	return cnt;
}

//查询数组中的最大数
int findMaxNum(int  *p, int n){
	int max = INT_MIN;
	for(int i = 0; i < n; i++){
		if(*(p + i) > max)
			max = *(p + i);
	}
	return max;
}

//将数字分配到各自的桶中 后按桶的顺序输出排序结果
void sort2(int *p, int n, int loop){
	int buckets[10][20]={};
	//求桶index的除数
	//如789 个位桶 index = (789/1) % 10 = 8;
	//十位桶 index = (789/10) % 10 = 9;
	//百位桶 index = (789/100) % 10 = 7;
	//tempNum为上式中的1、10、100
	int tempNum = (int) pow(10, loop - 1);
	for(int i = 0; i < n; i++){
		int row_index = (*(p + i) / tempNum)%10;
		for(int j = 0; j < 20; j++){
			if(buckets[row_index][j] == NULL){
				buckets[row_index][j] = *(p + i);
				break;
		}
	}
}

//将桶中的数 倒回到原数组
int k = 0;
for(int i = 0; i < 10; i++){
	for(int j = 0; j < 20; j++)
		if(buckets[i][j] != NULL){
			*(p + k) = buckets[i][j];
			buckets[i][j] = NULL;
			k++;
		}
	}
}
