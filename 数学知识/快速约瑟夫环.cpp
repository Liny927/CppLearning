/*
 * @Author: Hellcat
 * @Date: 2020-01-27 16:09:36
 * HDU 3098
 */
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
//f(i)=[f(i-1)+m]%i
int main()
{
    ll n,m;
    while(cin>>n>>m)
    {
        if(m == 1) {
            cout<<n<<endl;
            continue;
        }
        ll ans = 0, i = 2;
        while(i <= n)
        {
            if(ans + m < i)
            {
                ll num = (i - ans - 1) / (m - 1);
                if((i - ans - 1) % (m - 1) == 0)
                    num--;
                if(i + num > n)
                {
                    ans = (ans + (n - i + 1) * m) % n;
                    break;
                }else {
                    i+=num;
                    ans = (ans + m * num) % i;
                }
            }else {
                ans = (ans + m) % i;
                i++;
            }
        }
        cout<<(ans + 1ll)<<endl;
    }
    return 0;
}
/*
˼·��f(1)=0��f(i)=[f(i-1)+m]%i;����n�ǳ���
1����m=1��ʱ��Ӿ��������Ǹ�����
2: f(i-1)+m<i ��������ʱ����һ�¿��������ٴλ������������£��� f(i-1)+m*num<i-1+num ���������������num
���������ʼλ�õĻ������ģ�ans+s��%n���ɡ�
*/