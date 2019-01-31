#include<bits/stdc++.h>
using namespace std;
const int maxn=10005;
const int inf=0x7ffffff;
struct edge
{
	int nxt,to;
}e[maxn*2];
int head[maxn],tot,n,ans,f[maxn];
void add(int u,int v)
{
	e[tot].nxt=head[u];
	e[tot].to=v;
	head[u]=tot++;
}
void dfs(int u,int fa)
{
	int minx=inf,maxx=-inf;
	for(int i=head[u];i!=-1;i=e[i].nxt)
		if(e[i].to!=fa)
		{
			int v=e[i].to;
			dfs(v,u);
			minx=min(minx,f[v]);
			maxx=max(maxx,f[v]);
		}
	if(maxx+minx<=3)f[u]=minx+1;
	else f[u]=maxx+1;
	if(minx==inf)f[u]=3;
	if(f[u]==5)ans++,f[u]=0;
	if(fa==-1&&f[u]>2)ans++;
}
int main()
{
	memset(head,-1,sizeof(head));
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		add(i+1,x),add(x,i+1);
	}
	dfs(1,-1);
	cout<<ans<<endl;
	return 0;
}
