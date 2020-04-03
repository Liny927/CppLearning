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
思路：f(1)=0；f(i)=[f(i-1)+m]%i;这里n非常大。
1：当m=1的时候接就是最后的那个人了
2: f(i-1)+m<i 满足条件时，算一下可以跳多少次还在满足条件下，即 f(i-1)+m*num<i-1+num 求满足条件的最大num
如果加上起始位置的话对最后的（ans+s）%n即可。
*/