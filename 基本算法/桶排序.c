#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//Ͱ����(��������)
//Ͱ�����Ͱ��ʵ��һ��ָ��ָ���ָ�� Ͱ����Ҳ�ǽṹ��
int main(){
	int a[]={2, 32, 23, 342, 343, 34, 43, 348, 835, 987};
	int* a_p = a;
	int size = sizeof(a)/sizeof(int);
	bucketSort(a_p, size);
    for(int i = 0; i < size; i++)
        printf("%d\n", a[i]);
}

void bucketSort(int *p, int n){
	int maxNum = findMaxNum(p, n); //��ȡ�����е������
	int loopTimes = getLoopTimes(maxNum); //��ȡ����λ��
	for(int i = 1; i <= loopTimes; i++)
	{
		sort2(p, n, i);
	}
}

//��ȡ���ֵ�λ��
int getLoopTimes(int num){
	int cnt = 1;
	int temp = num/10;
	while(temp != 0){
		cnt++;
		temp = temp/10;
	}
	return cnt;
}

//��ѯ�����е������
int findMaxNum(int  *p, int n){
	int max = INT_MIN;
	for(int i = 0; i < n; i++){
		if(*(p + i) > max)
			max = *(p + i);
	}
	return max;
}

//�����ַ��䵽���Ե�Ͱ�� ��Ͱ��˳�����������
void sort2(int *p, int n, int loop){
	int buckets[10][20]={};
	//��Ͱindex�ĳ���
	//��789 ��λͰ index = (789/1) % 10 = 8;
	//ʮλͰ index = (789/10) % 10 = 9;
	//��λͰ index = (789/100) % 10 = 7;
	//tempNumΪ��ʽ�е�1��10��100
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

//��Ͱ�е��� ���ص�ԭ����
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
