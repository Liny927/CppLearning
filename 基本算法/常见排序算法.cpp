//bubble sort:冒泡排序的写法  
//冒泡排序法中的交换次数又称为反序数或逆序数,可用于体现数列的错乱程度

//常规：
//i用于表示未排序部分的开头元素 从数组头->末尾
//j用于对未排序部分中的相邻元素两两比较
for(int i = 1; i <= n - 1; i++){   //n个数排序 只用进行n-1趟
	//从第1位开始比较直到最后一个尚未归位的数
	for(int j = 0; j <= n - i - 1; j++) //<=> for(int j = n - 1; j > i; j--)  j从后往前循环(正宗)
		{
			if(a[j] < a[j+1]) //比较大小并交换
				swap(a[j], a[j+1]);
		}
	}


//优化：
//使用flag的冒泡排序法
int bubbleSort(int A[], int N) {
	int sw = 0;
	int flag = 1;
	for(int i = 0; flag; i++){ //增加flag 避免因已经有序的情况下无意义循环判断
		flag = 0;
		for(int j = N -1; j >= i + 1; j--){
			if(A[j-1] < A[j]) {
				swap(A[j - 1], A[j]);
				flag = 1;
				sw++;
			}
		}
	}
	return sw;
}


//选择排序法(0起点数组)：
//选择排序相当直观 会在每一步的排序中给出一个最值
//minj:记录各轮循环中的最小值的位置
//j:循环变量 用于查找最小值的位置
int selectionSort(int A[], int N){
	int i, j, t, sw = 0, minj;
	for(i = 0; i < N - 1; i++){
		minj = i;
		for(j = i; j < N; j++){
			if(A[j] < A[minj]) minj = j;
		}
		swap(A[j], A[minj]);
		if(i != minj) sw++;
	}
	return sw;
}


//插入排序法(0起点数组):
//直接插入排序:
int insertionSort(int A[], int N){
	int j, i, v, sw = 0;
	for(i = 1; i < N; i++){
		v = A[i];         //取出未排序部分的开头元素赋给变量v
		j = i - 1;
		while( j >= 0 && A[j] > v){  //在已排序部分 将所有比v大的元素向后移动一个单位
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = v;    //将已选出的元素v插入空位
		sw++;
	}
	return sw;
}

//折半插入排序:
void BinsertSort(SqList &L){
	for(i = 2; i <= L.length; i++){
		L.r[0] = L.r[i];
		int low = 1;
		high = i - 1;
		while(low <= high){   //r[low...high]中折半查找插入的位置
			m = (low + high)/2;
			if(L.r[0].key < L.r[m].key) high = m - 1;
			else low = m + 1;
		}
		for(j = i - 1; j >=high + 1; j--) L.r[j + 1] = L.r[j];
			L.r[high+1] = L.r[0];
	}
}


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


