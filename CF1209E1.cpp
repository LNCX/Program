#include<bits/stdc++.h>
using namespace std;
const int N=10,M=105;
int t,n,m,f[M][1<<N],a[N][M];
int solve(int x,int s)
{
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int res=0;
		for(int j=1;j<=n;j++)
			if(s&(1<<(j-1)))	
				res+=a[j][x];
		ans=max(res,ans);
		for(int j=n;j>=1;j--)
			a[j+1][x]=a[j][x];
        a[1][x]=a[n+1][x];
	}
	return ans;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		memset(f,0,sizeof(0));
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				scanf("%d",&a[i][j]);
		for(int i=1;i<=m;i++)
			for(int j=0;j<(1<<n);j++)
			{
				f[i][j]=f[i-1][j];
				for(int k=j;k!=0;k=(k-1)&j)
					f[i][j]=max(f[i][j],f[i-1][j-k]+solve(i,k));
			}
		printf("%d\n",f[m][(1<<n)-1]);
	}
	return 0;
}