#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int f[801][801][16][2],a[801][801];
int n,m,k,ans;
void dp()
{
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	for(int g=0;g<=k-1;g++)
	{
		f[i][j][g][0]=(f[i][j][g][0]+f[i-1][j][(g-a[i][j]+k)%k][1])%mod;
		f[i][j][g][0]=(f[i][j][g][0]+f[i][j-1][(g-a[i][j]+k)%k][1])%mod;
		f[i][j][g][1]=(f[i][j][g][1]+f[i-1][j][(g+a[i][j])%k][0])%mod;
		f[i][j][g][1]=(f[i][j][g][1]+f[i][j-1][(g+a[i][j])%k][0])%mod;
	}
}

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
		{
			scanf("%d",&a[i][j]);
			f[i][j][a[i][j]][0]=1;
		}
	k+=1;
	dp();
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
			ans=(ans+f[i][j][0][1])%mod;
	printf("%d\n",ans);
	return 0;
}
