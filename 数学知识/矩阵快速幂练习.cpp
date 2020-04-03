/*
 * @Author: Hellcat
 * @Date: 2020-02-06 12:32:02
 */
#include<bits/stdc++.h>
typedef long long int ll;
const int maxn = 1e6 + 5;
const ll  mod = 1e9 + 7;
using namespace std;

struct Mat{
    ll mat[4][4];
    Mat(){
        memset(mat,0,sizeof(mat));
    }
    Mat operator * (const Mat o)const{
        Mat ans;
        for(int i = 0;i < 4;i++){
            for(int j = 0;j < 4;j++){
                for(int k = 0;k < 4;k++){
                    ans.mat[i][j] = (ans.mat[i][j] + mat[i][k] * o.mat[k][j]) % (mod - 1);
                }
            }
        }
        return ans;
    }
}ans,res;

Mat matpow(Mat a,ll n){
    Mat ans;
    for(int i = 0;i < 4;i++) ans.mat[i][i] = 1;
    while(n){
        if(n & 1) ans = ans * a;
        a = a * a;
        n >>= 1;
    }
    return ans;
}

ll qpow(ll a,ll b){
    ll res = 1;
    while(b){
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void init1(){
    memset(ans.mat,0,sizeof ans);
    memset(res.mat,0,sizeof res);
    res.mat[0][0] = 0;res.mat[0][1] = 1;
    res.mat[1][0] = 1;res.mat[1][1] = 1;
}

void init2(){
    memset(ans.mat,0,sizeof ans);
    memset(res.mat,0,sizeof res);
    res.mat[0][0] = 0;res.mat[0][1] = 1;res.mat[0][2] = 0;
    res.mat[1][0] = 1;res.mat[1][1] = 1;res.mat[1][2] = 1;
    res.mat[2][0] = 0;res.mat[2][1] = 0;res.mat[2][2] = 1;
}

int main(){
    ll n,x,y,a,b;
    scanf("%lld %lld %lld %lld %lld",&n,&x,&y,&a,&b);
    if(n == 1) { printf("%lld\n",x % mod);return 0;}
    else if(n == 2) {printf("%lld\n",y % mod);return 0;}
    a = qpow(a%mod,b);x %= mod;y %= mod;
    init1();
    ans.mat[0][0] = 1;
    ans.mat[1][0] = 0;
    ans = matpow(res,n - 1) * ans;
    ll ans1 = ans.mat[0][0];
    init1();
    ans.mat[0][0] = 0;
    ans.mat[1][0] = 1;
    ans = matpow(res,n - 1) * ans;
    ll ans2 = ans.mat[0][0];
    init2();
    ans.mat[0][0] = 0;ans.mat[1][0] = 0;ans.mat[2][0] = 1;
    ans = matpow(res,n - 1) * ans;
    ll ans3 = ans.mat[0][0];
    cout<<ans1<<' '<<ans2<<' '<<ans3<<endl;
    if(x % mod == 0 || y % mod == 0 || a % mod == 0) puts("0");
    else {
        printf("%lld\n",qpow(x,ans1) * qpow(y,ans2) % mod * qpow(a,ans3) % mod);
    }
}
