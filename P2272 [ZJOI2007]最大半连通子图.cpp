#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
const int maxm=1000005;
int n,m,mod;
int e_num,head[maxm],x[maxm],y[maxm],nxt[maxm],to[maxm];
void get(int &x)
{
	char c=getchar();
	while(c<'0'||'9'<c) c=getchar();
	while('0'<=c&&c<='9')
	{
		x=(x<<3)+(x<<1)+(c-'0');
		c=getchar();
	}
	return ;
}
void add(int u,int v)
{
	nxt[++e_num]=head[u];
	to[e_num]=v;
	head[u]=e_num;
}//加边 
int num,sum,top,st[maxn],dfn[maxn],low[maxn],co[maxn],w[maxn];
void tarjan(int u)
{
	dfn[u]=low[u]=++num;
	top++;
	st[top]=u;
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
		w[sum]++;
		while(st[top]!=u)
		{
			co[st[top]]=sum;
			w[sum]++;
			top--;
		}
		top--;
	}
	return;
}//缩点
bool camp(int a,int b)
{
	if(x[a]!=x[b])
		return x[a]<x[b];
	return y[a]<y[b];
}
int dg[maxn],rnk[maxm];
void remove()
{
	for(int i=1;i<=m;i++)
	{
		rnk[i]=i;
		x[i]=co[x[i]];
		y[i]=co[y[i]];
	}
	sort(rnk+1,rnk+1+m,camp);
	e_num=0;
	memset(head,0,sizeof(head));
	memset(nxt,0,sizeof(nxt));
	for(int i=1;i<=m;i++)
	{
		int k=rnk[i];
		if(x[k]!=y[k]&&(x[k]!=x[rnk[i-1]]||y[k]!=y[rnk[i-1]]))//不在同一缩点 
		{
			dg[y[k]]++;
			add(x[k],y[k]);
		}
	}
	return ;
}//缩点调整
int ans,anss,l,r,dis[maxn],que[maxn],f[maxn];
void tuopu()
{
	for(int i=1;i<=sum;i++)
	{
		if(!dg[i])
		{
			r++;
			que[r]=i;
			dis[i]+=w[i];
			f[i]=1;
		}
		if(ans<dis[i]) ans=dis[i];
	}
	while(l<=r)
	{
		l++;
		int u=que[l];
		for(int i=head[u];i!=0;i=nxt[i])
		{
			int v=to[i];
			dg[v]--;
			if(dis[v]<dis[u]+w[v])
			{
				dis[v]=dis[u]+w[v];
				f[v]=0;
				if(ans<dis[v]) ans=dis[v];
			}
			if(dis[v]==dis[u]+w[v])
				f[v]=(f[v]+f[u])%mod;
			if(!dg[v]) que[++r]=v;
		}
	}
	return ;
}//拓扑排序
void dp()
{
	for(int i=1;i<=n;i++)
		if(dis[i]==ans)
			anss=(anss+f[i])%mod;
	return ;
}//动态规划 
int main()
{
	get(n),get(m),get(mod);
	for(int i=1;i<=m;i++)
	{
		get(x[i]),get(y[i]);
		add(x[i],y[i]);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i);
	remove();
	tuopu();
	dp();
	printf("%d\n%d",ans,anss);
	return 0;
}
