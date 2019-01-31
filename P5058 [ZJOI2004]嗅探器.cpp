#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
const int maxm=1e4+5;
const int inf=0x3f3f3f3f;
int n,m,x,y,ans=inf,root;
int nxt[maxm],head[maxn],to[maxm],edge_sum;
void add(int u,int v)
{
	nxt[++edge_sum]=head[u];
	to[edge_sum]=v;
	head[u]=edge_sum;
}
vector<int>bolck[maxn];
int dfn[maxn],low[maxn],s[maxn],top,num,bt,cut[maxn];
void tarjan(int u)
{
	dfn[u]=low[u]=++num;
	for(int i=head[u];i!=0;i=nxt[i])
	{
		int v=to[i];
		if(!dfn[v])
		{
			tarjan(v);
			low[u]=min(low[u],low[v]);
			if(u!=x&&u!=y)
				if(dfn[u]<=low[v]&&dfn[v]<=dfn[y]&&low[y]>=dfn[x])
					ans=min(ans,u);
		}
		low[u]=min(low[u],dfn[v]);
	}
}
int main()
{
	cin>>n;
	int u,v;
	while(scanf("%d%d",&u,&v)&&u!=0&&v!=0)
		add(u,v),add(v,u);
	cin>>x>>y;
	tarjan(x);
	if(ans!=inf) printf("%d\n",ans);
	else printf("No solution\n");
	return 0;
}

