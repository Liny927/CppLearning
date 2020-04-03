/*
 * @Author: Hellcat
 * @Date: 2020-01-15 09:52:56
 * P1019 ���ʽ��� dfs
 */
#pragma GCC optime(2)
#include <iostream>
#include <string.h>
#include <string>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#include <ctype.h>
#include <algorithm>
#define max(x,y) (x>y?x:y)
#define mes(a,b) memset(a,b,sizeof(a))
#define qwq(a,b) for(int i = (a); i < (b); ++i)
#define qeq(a,b) for(int j = (a); j < (b); ++j)
#define qaq(a,b) for(int k = (a); k > (b); --k)
typedef long long LL;
typedef unsigned long long ULL;
using namespace std;

int n;
int res = 0;
string words[100];
string now = "/0"; //��ǰ���һ������
int vis[100];

int check(string s1, string s2) {
    int len = min(s1.length(),s2.length());
    for(int i = 1; i < len ; i++)  //��������ַ���������ϵ
        if(s1.substr(s1.length() - i, i) == s2.substr(0,i))  //Ѱ�������ص��Ĳ���(̰��)
            return i;
    return 0;
}

void dfs(string s) {
    res = max(res, (int)s.length());
    qwq(0,n) {
        if(vis[i] == 2) continue;     //ֻ��ʹ��2��
        int res_c = check(s, words[i]);
        if(res_c == 0) continue;   //����ƴ��
        vis[i]++;
        dfs(s.substr(0,s.length() - res_c) + words[i]);  //ƴ�Ӻ�����
        vis[i]--;
    }
}

int main()
{
    cin>>n;
    mes(vis,0);
    qwq(0,n) {
        cin>>words[i];
    }
    char head;
    cin>>head;
    qwq(0,n)
        if(words[i][0] == head) {
            vis[i]++;   //��ͷ�ĵ���Ҳ��Ҫ����
            dfs(words[i]);
            vis[i]--;
        }
    cout<<res<<endl;
}