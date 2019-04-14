#include<bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
struct mat
{
	long long d[105][105];
}a,ans;
long long n,k;
mat mul(mat m)
{
	mat res;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
		res.d[i][j]=0;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	for(int k=1;k<=n;k++)
		res.d[i][j]=res.d[i][j]%mod+m.d[i][k]*a.d[k][j]%mod;
	return res;	
}
int main()
{
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
		scanf("%lld",&a.d[i][j]);
	for(int i=1;i<=n;i++)
		ans.d[i][i]=1;
	while(k)
	{
		if(k%2==1)
			ans=mul(ans);
		k/=2;
		a=mul(a);	
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			printf("%lld ",ans.d[i][j]%mod);
		printf("\n");
	}
}
