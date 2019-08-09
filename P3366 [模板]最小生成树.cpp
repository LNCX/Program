#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int k,g[N][N],used[N],dis[N],ans;
int main()
{
	int n,m,x,y,z;
	cin>>n>>m;
	memset(g,0x3f3f3f3f,sizeof(g));
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		if(g[x][y]>z)
			g[x][y]=g[y][x]=z;
	}
	memset(dis,0x3f3f3f3f,sizeof(dis));
	dis[1]=0;
	for(int i=1;i<=n;i++)
	{
		int min=0x7fffffff;
		for(int j=1;j<=n;j++)
			if(used[j]==0&&(min>dis[j]))
			{
				min=dis[j];
				k=j;
			}
		used[k]=1;
		ans+=min;
		for(int j=1;j<=n;j++)
			if(used[j]==0&&(dis[j]>g[k][j]))
				dis[j]=g[k][j];
	}
	cout<<ans<<endl;
}
