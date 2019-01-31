#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
int minx,k,ans,dis[105],used[105],g[105][105];
int main()
{
	int n;
	cin>>n;
	memset(g,inf,sizeof(g));
	memset(dis,inf,sizeof(dis));
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		int x;
		scanf("%d",&x);
		g[i][j]=x;
	}
	dis[1]=0;
	for(int i=1;i<=n;i++)
	{
		minx=inf;
		for(int j=1;j<=n;j++)
			if(!used[j]&&minx>dis[j])
			{
				minx=dis[j];
				k=j;
			}
		ans+=dis[k];
		used[k]=true;
		for(int j=1;j<=n;j++)
			if(!used[j]&&dis[j]>g[k][j])
				dis[j]=g[k][j];
	}
	cout<<ans<<endl;
}
