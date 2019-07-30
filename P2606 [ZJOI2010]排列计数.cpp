#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e6+6;
ll n,p,fac[N],f[N],s[N];
ll power(ll a,ll b)
{
    ll res=1;
    while(b)
    {
        if(b&1) res=(res*a)%p;
        a=a*a%p,b>>=1;
    }
    return res;
}
ll C(ll n,ll m)
{
	if(n<m) return 0;
	if(n<p&&m<p)
    {
		ll invn=power(fac[n-m],p-2);
		ll invm=power(fac[m],p-2);
		return fac[n]*invm%p*invn%p;
	}
	return C(n/p,m/p)*C(n%p,m%p)%p;
}
int main()
{
    scanf("%lld%lld",&n,&p);
    fac[0]=1;
    for(int i=1;i<=n;i++)
        fac[i]=(fac[i-1]*i)%p;
    for(int i=n;i>=1;i--)
    {
        int l=i<<1,r=i<<1|1;
        s[i]=s[l]+s[r]+1,f[i]=C(s[i]-1,s[l]);
		if(l<=n) f[i]=(f[i]*f[l])%p;
		if(r<=n) f[i]=(f[i]*f[r])%p;
    }
    printf("%lld\n",f[1]);
    return 0;
}