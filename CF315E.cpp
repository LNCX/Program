#include<bits/stdc++.h>
using namespace std;
#define lowbit(x) ((x)&(-x))
typedef long long LL;
const LL mod=1e9+7;
LL n,tree[3000005],a[1050000],dp[1050000],pre[1050000];
LL sum(LL x)
{
	LL sum=0;
	while(x>0)
	{
		sum+=tree[x];
		sum%=mod;
		x-=lowbit(x);
	}
	return sum;
}
LL add(LL x,LL c)
{
	while(x<=1000000+50)
	{
		tree[x]+=c;
		tree[x]%=mod;
		x+=lowbit(x);
	}
}
int main()
{
	scanf("%lld",&n);
	LL ans=0;
	memset(pre,-1,sizeof(pre));
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
	{
		dp[i]=sum(a[i])*a[i]+a[i];
		if(pre[a[i]]!=-1)dp[i]-=pre[a[i]];
		dp[i]=(dp[i]%mod+mod)%mod;
		ans+=dp[i];
		ans=(ans%mod+mod)%mod;
		pre[a[i]]=sum(a[i])*a[i]+a[i];
		add(a[i],dp[i]);
	}
	printf("%lld\n",(ans%mod+mod)%mod);
}