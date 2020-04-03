#pragma GCC optime(2)
#include <bits/stdc++.h>
#define lodou long double
//需要配合signed main()
//在需要大数据时候使用
#define int long long
#define mes(a,b) memset(a,b,sizeof(a))
#define qwq(a,b) for(int i=a; i<b; ++i)
#define qeq(a,b) for(int j=a; j<b; ++j)
#define pb push_back
typedef long long LL;
typedef unsigned long long ULL;
using namespace std;
const int MAXN=1e3+10;
#define N 100000
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
//#define TEST //不需要测试时注释掉该行
using namespace std;

//递归实现的斐波那契 效率低 但胜在简洁
int fib1(int n){
  if(n==1||n==2) return 1;
  return fib1(n-1)+fib1(n-2);
}

//一维数组实现的斐波那契 打表思想 效率一般
ULL f[1280];
void fib2(){
  f[0]=0;
  f[1]=1;
  f[2]=1;
  for(int i=3;i<1280;i++)
    f[i]=f[i-2]+f[i-1];
}

//二维数组(进位)实现的斐波那契 
ULL a[1005][1005];
void fib3(int n){
  int c;
  int d=0;
  a[1][0]=1;
  a[2][0]=1;
  for(int i=3;i<=n;++i){
    c=0; //保存余数
    for(int j=0;j<=d;++j){
      a[i][j]=a[i-1][j]+a[i-2][j]+c;
      c=a[i][j]/10; //将其他数进位
      a[i][j]%=10;  //大于10的数取余数
    }
    while(c){
      a[i][++d]=c%10;
      c/=10;
    }
  }
  for(int i=d;i>=0;i--)
    printf("%d",a[n][i]);
  cout<<endl;
}


signed main(){
  int n;
  int T;
  scanf("%d",&T);
  while(T--){
    scanf("%d",&n);
    fib3(n);
  }
  scanf("%d",&n);
  fib2();
  cout<<f[n]<<endl;
}