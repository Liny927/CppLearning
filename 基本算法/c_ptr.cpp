#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
int main(){
	int a=12;
	//����nullptr����ʼ��ָ�� ���Ա�ת�����������͵�����ָ��
	int *b=nullptr;
	b=&a;//ָ����Ϊ��ֵʱ��������
	if(b) printf("ָ��b��ֵ��%d\n",b);

	int **c=&b;//�൱��*(*c) ָ��ָ���ָ��
	//*c����cָ���λ�� ������b �ڶ���*���ʱ���bָ��ĵ�ַ ���Ǳ���a
	printf("**cֵΪ��%d\n *(*c)ֵΪ%d\n",**c,*(*c));
	printf("b=%#x\n&a=%p\nc=%p\n*c=%p\n",b,&a,c,*c);//%p�������ָ���ַ %#x�����ǰ׺��16���Ƶ�ַ
	*&a=14;
	printf("����*&������aֵ�ı�Ϊ��%d\n",a);

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
	//�κε�ַ����д��void���͵�ָ��
	void *pv=NULL;
	pv=&obj;
	//��voidָ��ǿ��ת����ԭ��������
	double *dp=static_cast<double*>(pv);

	string nums[]={"one","two","three"};
	string *u=nums;

	//ָ��Ҳ������Ϊ������
	int arr[]={0,1,2,3,4,5};
	int *v=arr;
	++v;

	char are[]={"erwhtreh"};
	char *beg=begin(are);
	char *last=end(are);
}

//ʵ��Ӧ�� �жϻ��Ĵ�
int is_huiwen(char*p)  
{  
    char*q=p;  
    while(*q) 
        q++;  
    q--;//ָ��'\0'֮ǰ��λ��  '\0'����ж����Ӱ�� qΪβָ��
    while(p<q)  
        //�����ж��Ƿ����  
        if(*p++!=*q--) return 0;  
    return 1;  
}

//��дstring.h�⺯��
int strcmp(const char *str1,const char *str2)
{
    /*������while(*str1++==*str2++)���Ƚϣ��������ʱ�Ի�ִ��һ��++��
    return���صıȽ�ֵʵ��������һ���ַ���Ӧ��++�ŵ�ѭ�����н��С�*/
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