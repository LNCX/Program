#include<bits/stdc++.h>
using namespace std;
const int mod=20100403;
typedef long long LL;
LL C(LL x,LL y)
{
	LL a=1;
	for(LL i=2;i<=x;i++) 
		a=(a*i)%mod;
	LL b=1;
	for(LL i=2;i<=y;i++)
		b=(b*i)%mod;
	LL c=1;
	for(LL i=2;i<=x-y;i++)
		c=(c*i)%mod;
	b=(b*c)%mod;
	LL d=1;
	LL p=mod-2;
	while(p>0) 
	{
		if(p%2==1)d=(d*b)%mod;
		b=(b*b)%mod;
		p/=2;
	}
	return (a*d)%mod;
}
int main()
{
	LL n,m;
	scanf("%lld%lld",&n,&m);
	printf("%lld",(C(n+m,n)-C(n+m,n+1)+mod)%mod);
	return 0;
}
