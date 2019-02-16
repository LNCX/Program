#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=5e4+5;
struct Edge
{
	int v,w,nxt;
}e[maxn<<1];
struct node
{
	int num,w;
	bool operator<(const node &x) const
	{
		return w<x.w;
	}
}son[maxn],kil[maxn];
LL l,r;
int n,m,head[maxn],tot,trp[maxn];
int f[maxn][25],d[maxn][25],tot1,tot2,con[maxn];
void add(int u,int v,int w)
{
	e[++tot].nxt=head[u];
	e[tot].v=v;
	e[tot].w=w;
	head[u]=tot;
}
void dfs(int u,int fa,LL len)
{
	f[u][0]=fa,d[u][0]=len;
	for(int i=0;i<17;i++)
	{
		f[u][i+1]=f[f[u][i]][i];
		d[u][i+1]=d[u][i]+d[f[u][i]][i];
	}
	for(int i=head[u];i!=0;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs(v,u,e[i].v);
	}
}
bool dfs1(int u,int fa)
{
	if(con[u]) return false;
	for(int i=head[u];i!=0;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		if(!dfs1(v,u)) return false;
	}
	return true;
}
bool check(int t)
{
	for(int i=1;i<=n;i++)
		con[i]=0;
	for(int i=1;i<=m;i++)
	{
		LL tim=0;
		int u=trp[i];
		for(int i=17;i>=0;i--)
			if(tim+d[u][i]<=t&&f[u][i]>1)
				tim+=d[u][i],u=f[u][i];
		if(f[u][0]==1&&tim+d[u][0]<t)
		{
			kil[++tot2].num=u;
			kil[tot2].w=d[u][0]+tim;
		}
		else con[u]=1;
	}
	for(int i=head[1];i!=0;i=e[i].nxt)
	{
		if(dfs1(e[i].v,1)) con[e[i].v]=1;
		else son[++tot1].num=e[i].v,son[tot].w=e[i].w;
	}
	sort(kil+1,kil+1+n);
	for(int i=1;i<=tot2;i++)
	{
		int u=kil[i].num;
		if(kil[i].w+d[u][0]>t&&!con[u])
		{
			con[u]=1;
			kil[i].w=-0x3f3f3f3f;
		}
	}
	while(tot1>0&&tot2>0)
	{
		if(kil[tot2].w==-1)
		{
			tot2--;
			continue;
		}
		if(con[son[tot1].num]==1)
		{
			tot1--;
			continue;
		}
		if(kil[tot2].w<son[tot1].w)
			return false;
		else tot2--,tot1--;
	}
	if(tot2==0&&tot1!=0) return false;
	return true;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w),add(v,u,w);
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
		scanf("%d",&trp[i]);
	dfs(1,0,0);
	LL ans=-1;
	while(l<=r)
	{
		LL mid=(l+r)>>1;
		if(check(mid)) r=mid-1,ans=mid;
		else l=mid+1;
	}
	cout<<ans<<endl;
	return 0;
}