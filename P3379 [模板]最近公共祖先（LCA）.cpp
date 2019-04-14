#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int e_num,head[2*maxn],to[2*maxn],nxt[2*maxn];
void add(int u,int v)
{
	nxt[++e_num]=head[u];
	to[e_num]=v;
	head[u]=e_num;
}
int dep[maxn],f[maxn][21];
void deal(int u,int fa)
{
	dep[u]=dep[fa]+1;
	for(int i=0;i<=19;i++)
		f[u][i+1]=f[f[u][i]][i];
	for(int i=head[u];i!=0;i=nxt[i])
	{
		int v=to[i];
		if(v==fa) continue;
		f[v][0]=u;
		deal(v,u);
	}
	return ;
}
int lca(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=20;i>=0;i--)
	{
		if(dep[f[x][i]]>=dep[y]) 
			x=f[x][i];
		if(x==y) return x;
	}
	for(int i=20;i>=0;i--)
		if(f[x][i]!=f[y][i])
		{
			x=f[x][i];
			y=f[y][i];
		}
	return f[x][0];
}
int main()
{
	int n,m,s;
	scanf("%d%d%d",&n,&m,&s);
	for(int i=1;i<=n-1;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	deal(s,0);
	for(int i=1;i<=m;i++)
	{
		int a,b,ans;
		scanf("%d%d",&a,&b);
		printf("%d\n",lca(a,b));
	}
	return 0;
}
