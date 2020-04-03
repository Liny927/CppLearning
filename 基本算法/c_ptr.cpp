#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
int main(){
	int a=12;
	//利用nullptr来初始化指针 可以被转化成任意类型的其他指针
	int *b=nullptr;
	b=&a;//指针作为左值时当作变量
	if(b) printf("指针b的值是%d\n",b);

	int **c=&b;//相当于*(*c) 指向指针的指针
	//*c访问c指向的位置 即变量b 第二个*访问变量b指向的地址 就是变量a
	printf("**c值为：%d\n *(*c)值为%d\n",**c,*(*c));
	printf("b=%#x\n&a=%p\nc=%p\n*c=%p\n",b,&a,c,*c);//%p可以输出指针地址 %#x输出带前缀的16进制地址
	*&a=14;
	printf("经过*&操作后a值改变为：%d\n",a);

	int d;
	int m=2,n=3;
	int *pa=&m;
	int *pb=&n;
	d=*pa*(*pb);
	printf("d=%d\n",d);
	d=++(*pa)+(++(*pb));
	printf("d=%d\n",d);
	d=(*pa)+++*pb; //<=>d=((*pa)++)+*pb;
	printf("m=%d n=%d\n",m,n);

	double obj=3.14159;
	//任何地址都能写入void类型的指针
	void *pv=NULL;
	pv=&obj;
	//将void指针强制转换回原来的类型
	double *dp=static_cast<double*>(pv);

	string nums[]={"one","two","three"};
	string *u=nums;

	//指针也可以作为迭代器
	int arr[]={0,1,2,3,4,5};
	int *v=arr;
	++v;

	char are[]={"erwhtreh"};
	char *beg=begin(are);
	char *last=end(are);
}

//实例应用 判断回文串
int is_huiwen(char*p)  
{  
    char*q=p;  
    while(*q) 
        q++;  
    q--;//指向'\0'之前的位置  '\0'会对判断造成影响 q为尾指针
    while(p<q)  
        //遍历判断是否相等  
        if(*p++!=*q--) return 0;  
    return 1;  
}

//手写string.h库函数
int strcmp(const char *str1,const char *str2)
{
    /*不可用while(*str1++==*str2++)来比较，当不相等时仍会执行一次++，
    return返回的比较值实际上是下一个字符。应将++放到循环体中进行。*/
    while(*str1 == *str2)
    {
    	assert((str1 != nullptr) && (str2 != nullptr));                
        if(*str1 == '\0')
            return 0;        
        str1++;
        str2++;
    }
    return *str1 - *str2;
}