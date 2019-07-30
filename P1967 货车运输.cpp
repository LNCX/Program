#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+5,maxm=5e4+5,maxb=15,inf=0x3f3f3f3f;
struct Edge
{
	int u,v,w;
	bool operator < (const Edge& rhs) const
	{
		return w>rhs.w;
	}
} edge[maxm];
int fa[maxn],d[maxn],fan[maxn][maxb],mine[maxn][maxb];
int f(int i)
{
	if(i==fa[i]) return i;
	else return fa[i]=f(fa[i]);
}
int dfs(int v)
{
	if(d[v]) return d[v];
	if(f(v)) return d[v]=dfs(fan[v][0])+1;
	else return 1;
}
int LCA(int x,int y)
{
	if(d[x]<d[y]) swap(x,y);
	int i,j,mmin=inf;
	for(i=0;(1<<i)<=d[x];i++);
	i--;
	for(j=i;j>=0;j--)
		if(d[x]-(1<<j)>=d[y])
			mmin=min(mmin,mine[x][j]),x=fan[x][j];
	if(x==y) return mmin;
	for(j=i;j>=0;j--)
		if(fan[x][j]!=fan[y][j])
		{
			mmin=min(mmin,min(mine[x][j],mine[y][j]));
			x=fan[x][j],y=fan[y][j];
		}
	return min(mmin,min(mine[x][0],mine[y][0]));
}
int main()
{
	int n,m,x,y,z,cnt=0;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=m; ++i)
	{
		scanf("%d%d%d",&x,&y,&z);
		edge[i].u=x,edge[i].v=y,edge[i].w=z;
	}
	sort(edge+1,edge+m+1);
	for(int i=1; i<=n; ++i) fa[i]=i;
	memset(mine,inf,sizeof(mine));
	for(int i=1; i<=m&&cnt<n-1; ++i)
	{
		int u=f(edge[i].u),v=f(edge[i].v),w=edge[i].w;
		if(u!=v) fa[v]=u,fan[v][0]=u,mine[v][0]=w,++cnt;
	}
	for(int i=1;i<=n;i++)
	{
		int root=f(i);
		d[root]=1;
		if(!d[i])dfs(i);
	}
	for(int j=1;j<maxb;j++)
		for(int i=1; i<=n;i++)
		{
			fan[i][j]=fan[fan[i][j-1]][j-1];
			mine[i][j]=min(mine[i][j-1],mine[fan[i][j-1]][j-1]);
		}
	int q;
	scanf("%d",&q);
	for(int i=1; i<=q; ++i)
	{
		scanf("%d%d",&x,&y);
		if(f(x)!=f(y)) cout<<-1<<endl;
		else printf("%d\n",LCA(x,y));
	}
	return 0;
}