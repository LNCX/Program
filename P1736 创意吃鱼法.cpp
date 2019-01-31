#include<bits/stdc++.h>
using namespace std;
int n,m,ans,a[2505][2505];
int b[2505][2505],c[2505][2505],f[2505][2505];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
		scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		if(!a[i][j])
		{
			b[i][j]=b[i][j-1]+1;
			c[i][j]=c[i-1][j]+1;
		}
		if(a[i][j])
			f[i][j]=min(f[i-1][j-1],min(b[i][j-1],c[i-1][j]))+1;
		ans=max(ans,f[i][j]);
	}
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++)
	for(int j=m;j>=1;j--)
	{
		if(!a[i][j])
		{
			b[i][j]=b[i][j+1]+1;
			c[i][j]=c[i-1][j]+1;
		}
		if(a[i][j])
			f[i][j]=min(f[i-1][j+1],min(b[i][j+1],c[i-1][j]))+1;
		ans=max(ans,f[i][j]);
	}
	cout<<ans<<endl;
}

