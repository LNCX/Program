#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
ll f[100005],n,k,l,r;
ll power(ll a,ll b)
{
    ll res=1;
    a%=mod;
    while(b)
    {
        if(b&1) res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}
int main()
{
    ll kl=0,x,y,len;
    scanf("%lld%lld%lld%lld",&n,&k,&l,&r);
    if(l<=k&&k<=r)kl=1;
    l--,l/=k,r/=k,len=r-l;
    for(ll i=len;i>=1;i--)
    {
        x=l/i,y=r/i;
        f[i]=(power(y-x,n)-(y-x)+mod)%mod;
        for(ll j=i<<1;j<=len;j+=i)f[i]=(f[i]-f[j]+mod)%mod;
    }
    printf("%lld\n",f[1]+kl);
    return 0;
}