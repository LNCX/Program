#include<bits/stdc++.h>
using namespace std;
const int N=10005;
const int maxm=50005;
int n,m,dg[N];
int edge_num,head[maxm],to[maxm],nxt[maxm];
void add(int u,int v)
{
	nxt[++edge_num]=head[u];
	to[edge_num]=v;
	head[u]=edge_num;
}
int co[N],st[N],top;
int dfn[N],low[N],num,sum,like[N];
void tarjan(int u)
{
	dfn[u]=low[u]=++num;
	st[++top]=u;
	for(int i=head[u];i!=0;i=nxt[i])
	{
		int v=to[i];
		if(!dfn[v])
		{
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(!co[v])
			low[u]=min(low[u],dfn[v]);	
	}
	if(dfn[u]==low[u])
	{
		co[u]=++sum;
		like[sum]++;
		while(st[top]!=u)
		{
			like[sum]++;
			co[st[top]]=sum;
			top--;
		}
		top--;
	}
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(y,x);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i);
	for(int i=1;i<=n;i++)
		for(int j=head[i];j!=0;j=nxt[j])
			if(co[i]!=co[to[j]])
				dg[co[to[j]]]++;
	int ans=0,u=0;
	for(int i=1;i<=sum;i++)
		if(!dg[i])
			ans=like[i],u++;
	if(u==1)
		printf("%d\n",ans);
	else
		printf("0\n");
	return 0;
}
