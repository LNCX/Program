#include<bits/stdc++.h>
using namespace std;
bool used[2305];
int ans,dis[2305],g[2305][2305];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	memset(g,0x3f3f3f3f,sizeof(g));
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		if(g[x][y]>z)
			g[x][y]=g[y][x]=z;
	}
	memset(dis,0x3f3f3f3f,sizeof(dis));
	dis[0]=0;
	for(int i=0;i<=n;i++)
	{
		int k=2304;
		for(int j=0;j<=n;j++)
			if(!used[j]&&(dis[j]<dis[k]))
				k=j;
		used[k]=true;
		ans+=dis[k];
		for(int j=0;j<=n;j++)
			if(!used[j]&&dis[j]>g[k][j])
				dis[j]=g[k][j];
	}
	cout<<ans<<endl;
}
