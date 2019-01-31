#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
long long n,res,ans;
int nxt[maxn],head[maxn],to[maxn],edge_sum;
void add(int u,int v)
{
	nxt[++edge_sum]=head[u];
	to[edge_sum]=v;
	head[u]=edge_sum;
}
vector<int>block[maxn];
int bt,dfstime,root,top;
int sta[maxn],cut[maxn],dfn[maxn],low[maxn];
void tarjan(int u)
{
	dfn[u]=low[u]=++dfstime;
	sta[++top]=u;
	int cnt=0;
	for(int i=head[u];i!=0;i=nxt[i])
	{
		int v=to[i];
		if(!dfn[v])
		{
			cnt++;
			tarjan(v);
			low[u]=min(low[u],low[v]);
			if((u==root&&cnt>1)||(u!=root&&dfn[u]<=low[v])) cut[u]=1;
			if(dfn[u]<=low[v])
			{
				block[++bt].clear();
				do	block[bt].push_back(sta[top--]);
				while(sta[top+1]!=v);
				block[bt].push_back(u);
			}
		}
		else low[u]=min(low[u],dfn[v]);
	}
}
void clear()
{
	bt=0;
	top=0;
	dfstime=0;
	edge_sum=0;
	memset(head,0,sizeof(head)); 
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	memset(cut,0,sizeof(cut));
	memset(nxt,0,sizeof(nxt));
}
void solve()
{
	clear();	
	for(int i=1;i<=n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);	
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
		{
			root=i;
			tarjan(i);
		}
	res=0,ans=1;
	for(int i=1;i<=bt;i++)
	{
		int gnum=0,len=block[i].size();
		for(int j=0;j<len;j++)
			if(cut[block[i][j]]) gnum++;
		if(gnum==0)
		{
			res+=2;
			ans=ans*(len-1)*len/2;	
		}
		else if(gnum==1)
		{
			res++;
			ans=ans*(len-1);
		}
	}
}
int main()
{
	int T=1;
	while(scanf("%lld",&n)&&n)
	{
		solve();
		printf("Case %d: %lld %lld\n",T++,res,ans);
	}
	return 0;
}
