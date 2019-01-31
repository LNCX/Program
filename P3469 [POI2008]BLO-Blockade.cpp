#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
const int maxm=1e6+5;
int n,m;
long long ans[maxn];
int edge_sum,head[maxm],nxt[maxm],to[maxm];
void add(int u,int v)
{
	nxt[++edge_sum]=head[u];
	to[edge_sum]=v;
	head[u]=edge_sum;
}

int dfstime,dfn[maxn],low[maxn],size[maxn];
void tarjan(int u)
{
	int cnt=0;size[u]=1;
	dfn[u]=low[u]=++dfstime;
	for(int i=head[u];i!=0;i=nxt[i])
	{
		int v=to[i];
		if(!dfn[v])
		{
			tarjan(v);
			size[u]+=size[v];
			low[u]=min(low[u],low[v]);
			if(dfn[u]<=low[v])
			{
				ans[u]+=(long long)cnt*size[v];
				cnt+=size[v];
			}
		}
		else low[u]=min(low[u],dfn[v]);
	}
	ans[u]+=(long long)cnt*(n-cnt-1);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
	}
	tarjan(1);
	for(int i=1;i<=n;i++) 
		printf("%lld\n",(ans[i]+n-1)<<1);
	return 0;
}
