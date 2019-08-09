#include<bits/stdc++.h>
using namespace std;
void read(){}
template<typename T,typename... Ts>
inline void read(T &arg,Ts&... args)
{
    T x=0,f=1;
    char c=getchar();
    while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
    while(isdigit(c)){x=(x<<3)+(x<<1)+(c-'0');c=getchar();}
    arg=x*f;
    read(args...);
}
typedef long long ll;
const int N=1e6+5;
const ll mod=100000007;
int n,q;
ll a[N]={1},mul[N],sum[N],sum1[N];
ll power(ll a,ll b)
{
    a%=mod;
    ll res=1;
    while(b)
    {
        if(b&1) (res*=a)%=mod;
        (a*=a)%=mod,b>>=1;
    }
    return res;
}
int main()
{
    read(n,q);
    for(int i=1;i<=n;i++)
    {
        read(a[i]);
        mul[i]=(a[i]*mul[i-1]+a[i])%mod;
        sum[i]=(sum[i-1]+mul[i])%mod;
        a[i]=(a[i]*a[i-1])%mod;
        sum1[i]=(sum1[i-1]+a[i])%mod;
    }
    while(q--)
    {
        int l,r;
        read(l,r);
        ll x=( (sum1[r]-sum1[l-1])*power(a[l-1],mod-2)%mod ) * mul[l-1]%mod;
        ll res=(sum[r]-sum[l-1]-x)%mod;
        res=res*power((r-l+1)*(r-l+2)/2,mod-2)%mod;
        printf("%lld\n",(res%mod+mod)%mod);
    }
    return 0;
}