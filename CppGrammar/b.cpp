/*
 * @Author: Hellcat
 * @Date: 2020-03-30 21:27:39
 */
#include <iostream>
using namespace std;

typedef struct Stag
{
    /* data */
    int a, b, c, d;
}S;

int main() {
    double x = 0;
    double* p = &x;
    double& r = x;
    cout<<sizeof(x)<<endl;// 8
    cout<<sizeof(p)<<endl;// 8
    cout<<sizeof(r)<<endl;// 8
    cout<<p<<endl;      // 0x61fe08
    cout<<*p<<endl;     // 0
    cout<<x<<endl;      // 0
    cout<<r<<endl;      // 0
    cout<<&x<<endl;     // 0x61fe08
    cout<<&r<<endl;     // 0x61fe08
    S s;
    S& rs = s;
    cout<<sizeof(s)<<endl; // 16
    cout<<sizeof(rs)<<endl; // 16
    cout<<&s<<endl;  // 0x61fdf0
    cout<<&rs<<endl; // 0x61fdf0
}
// 结论: object和其reference的大小相同 地址也相同(全都是假象)
