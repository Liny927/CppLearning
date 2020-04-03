/*
 * @Author: Hellcat
 * @Date: 2020-01-30 12:32:32
 */
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(){
    clock_t start, end;
    long long k, n = 1e8;
	start = clock();		// 程序开始计时
    for(long long i = 0; i < n; i++) k++;
	end = clock();		    // 程序结束用时
	double endtime = (double)(end - start) / CLOCKS_PER_SEC;
	cout<<"Total time:"<<endtime<<endl;		//s为单位
	cout<<"Total time:"<<endtime * 1000<<"ms"<<endl;	//ms为单位
	return 0;
}
