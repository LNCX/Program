#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int n,t;
ll a[maxn],val[maxn],dp[400][400],dis[400][400],ans=0x3f3f3f3f;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(a[i]!=0)val[++t]=a[i];
	}
	if(t>3*64)return puts("3"),0;
	for(int i=1;i<=t;i++)
	    for(int j=1;j<=t;j++)
	        if(i!=j&&((val[i]&val[j])!=0))
                dis[i][j]=1,dp[i][j]=1;
	        else dp[i][j]=dis[i][j]=0x3f3f3f3f;
	for(int k=1;k<=t;k++)
	{
		for(int i=1;i<k;i++)
		    for(int j=i+1;j<k;j++)
		        ans=min(dp[i][j]+dis[i][k]+dis[k][j],ans);
		for(int i=1;i<=t;i++)
		    for(int j=1;j<=t;j++)
		        dp[i][j]=min(dp[i][k]+dp[k][j],dp[i][j]);
	}
	if(ans==0x3f3f3f3f)puts("-1");
	else printf("%lld\n",ans);
}