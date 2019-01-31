#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
typedef long long LL;
int n,m;
LL sum[maxn<<2],add[maxn<<2];
int seg[maxn],top[maxn],rev[maxn];
int size[maxn],son[maxn],dep[maxn],fa[maxn];
int edge_sum,num[maxn<<1],nxt[maxn<<1],to[maxn<<1],head[maxn<<1];
void edge_add(int u,int v)
{
	nxt[++edge_sum]=head[u];
	to[edge_sum]=v;
	head[u]=edge_sum;
}
void dfs1(int u,int f)
{
	fa[u]=f;
    size[u]=1;
	dep[u]=dep[f]+1;
	for(int i=head[u];i!=0;i=nxt[i])
	{
		int v=to[i];
		if(v==f) continue;
		dfs1(v,u);
		size[u]+=size[v];
		if(size[v]>size[son[u]]) son[u]=v;
	}
}
void dfs2(int u)
{
	if(son[u])
	{
		seg[son[u]]=++seg[0];
		top[son[u]]=top[u];
		rev[seg[0]]=son[u];
		dfs2(son[u]);
	}
	for(int i=head[u];i!=0;i=nxt[i])
	{
		int v=to[i];
		if(!top[v])
		{
			seg[v]=++seg[0];
			top[v]=v;
			rev[seg[0]]=v;
			dfs2(v);
		}
	}
}
void build(int k,int l,int r)
{
	if(l==r)
	{
		sum[k]=num[rev[l]];
		return;
	}
	int mid=(l+r)>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	sum[k]=sum[k<<1]+sum[k<<1|1];
}
void down(int k,int l,int r,int mid)
{
	if(!add[k]) return ;
	sum[k<<1]+=add[k]*(mid-l+1);
	sum[k<<1|1]+=add[k]*(r-mid);
	add[k<<1]+=add[k],add[k<<1|1]+=add[k];
	add[k]=0;
}
void Add(int k,int l,int r,int x,int y,int a)
{
	if(x<=l&&r<=y)
	{
		add[k]+=a;
		sum[k]+=(LL)(r-l+1)*a;
		return;
	}
	int mid=(l+r)>>1;
	down(k,l,r,mid);
	if(mid>=x) Add(k<<1,l,mid,x,y,a);
	if( mid<y) Add(k<<1|1,mid+1,r,x,y,a);
	sum[k]=sum[k<<1]+sum[k<<1|1];
}
LL query(int k,int l,int r,int x,int y)
{
	LL ans=0;
	if(x<=l&&r<=y) return sum[k];
	int mid=(l+r)>>1;
	down(k,l,r,mid);
	if(x<=mid) ans+=query(k<<1,l,mid,x,y);
	if( mid<y) ans+=query(k<<1|1,mid+1,r,x,y);
	return ans;
}
LL ask(int x)
{
	LL ans=0;
	int fx=top[x];	
	while(fx!=1)
	{
		ans+=query(1,1,n,seg[fx],seg[x]);
		x=fa[fx],fx=top[x];
	}
	ans+=query(1,1,n,1,seg[x]);
	return ans;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		scanf("%d",&num[i]);
	for(int i=1;i<=n-1;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		edge_add(x,y),edge_add(y,x);
	}
	dfs1(1,0);
	seg[0]=seg[1]=top[1]=rev[1]=1;
	dfs2(1);
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		int op,x,a;
		scanf("%d%d",&op,&x);
		if(op==1)
		{
			scanf("%d",&a);
			Add(1,1,n,seg[x],seg[x],a);
		}
		else if(op==2)
		{
			scanf("%d",&a);
			Add(1,1,n,seg[x],seg[x]+size[x]-1,a);
		}
		else if(op==3)
			printf("%lld\n",ask(x));
	}
	return 0;
}
