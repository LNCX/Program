#include<bits/stdc++.h>
using namespace std;
const int N=1005;
const int mod=10007;
int c[N][N];
int a,b,k,n,m;
int pow(int x,int y)
{
	int ans=1,pas=x;
	while(y)
	{
		if(y&1)ans*=pas%mod,ans%=mod;
		pas=(pas*pas)%mod;
		y>>=1;
	}
	return ans%mod;
}
int dfs(int n,int m)
{
	if(!m)return c[n][m]=true;
	if(m==1)return c[n][m]=n;
	if(c[n][m])return c[n][m];
	if(n-m<m)	m=n-m;
	return c[n][m]=(dfs(n-1,m)+dfs(n-1,m-1))%mod;
}
int main()
{
	scanf("%lld%lld%lld%lld%lld",&a,&b,&k,&n,&m);
	c[1][0]=c[1][1]=1;
	a%=mod;b%=mod;
	int ans=1;
	ans*=(pow(a,n)*pow(b,m))%mod;
	if(n>m)	n=m;
	ans*=dfs(k,n)%mod;
	ans%=mod;
	printf("%lld",ans);
	return 0;
}
