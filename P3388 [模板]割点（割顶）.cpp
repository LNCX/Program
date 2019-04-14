#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
const int maxm=100005;
int ans,cut[maxn];
int e_num,head[maxm],to[maxm],nxt[maxm];
void add(int u,int v)
{
	nxt[++e_num]=head[u];
	to[e_num]=v;
	head[u]=e_num;
	return ;
}
int num,sum,root,co[maxn],dfn[maxn],low[maxn];
void tarjan(int u)
{
	low[u]=dfn[u]=++num;
	int cnt=0;
	for(int i=head[u];i!=0;i=nxt[i])
	{
		int v=to[i];
		if(!dfn[v])
		{
			cnt++;
			tarjan(v);
			low[u]=min(low[u],low[v]);
			if((u==root&&cnt>1)||(u!=root&&dfn[u]<=low[v]))
			{
				cut[u]=1;
				ans++;
			}
		}
		else low[u]=min(low[u],dfn[v]);
	}
	return ;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)	
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
		{
			root=i;
			tarjan(i);
		}
	printf("%d\n",ans);
	for(int i=1;i<=n;i++)
		if(cut[i])
			printf("%d ",i);
	return 0;
}
