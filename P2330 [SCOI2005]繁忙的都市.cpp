#include<bits/stdc++.h>
using namespace std;
const int N=305;
const int inf=0x3f3f3f3f;
int main()
{
	int n,m,s,k,minn,ans=-1;
	int g[N][N],d[N],used[N];
	scanf("%d%d",&n,&m);
	memset(g,inf,sizeof(g));
	memset(d,inf,sizeof(d));
	memset(used,0,sizeof(used));
	for(int i=1;i<=m;i++)
	{
		int u,v,c;
		scanf("%d%d%d",&u,&v,&c);
		g[u][v]=c;
		g[v][u]=c;
	}
	d[1]=0;
	for(int i=1;i<=n;i++)
	{
		k=0;
		for(int j=1;j<=n;j++)
			if(!used[j]&&d[j]<d[k])
				k=j;
		used[k]=true;
		for(int j=1;j<=n;j++)
			if(!used[j]&&d[j]>g[k][j]&&g[k][j]!=0)
				d[j]=g[k][j];
	}
	for(int i=1;i<=n;i++)
		if(d[i]>ans)
			ans=d[i];
	printf("%d %d\n",n-1,ans);
}
