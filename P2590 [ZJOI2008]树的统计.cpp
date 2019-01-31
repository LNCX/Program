#include<bits/stdc++.h>
using namespace std;
const int N=60005;
int n,m,maxx,summ;
int seg[N],rev[N],size[N],son[N],top[N];
int num[N],father[N],dep[N],sum[N<<2],maxn[N<<2];
int e_num,head[N<<2],to[N<<2],nxt[N<<2];
void add(int u,int v)
{
	nxt[++e_num]=head[u];
	to[e_num]=v;
	head[u]=e_num;
}
void dfs1(int u,int f)
{
	size[u]=1;
	father[u]=f;
	dep[u]=dep[f]+1;
	for(int i=head[u];i!=0;i=nxt[i])
	{
		int v=to[i];
		if(v!=f)
		{
			dfs1(v,u);
			size[u]+=size[v];
			if(size[v]>size[son[u]]) son[u]=v;
		}
	}
}
void dfs2(int u,int f)
{
	if(son[u])
	{
		seg[son[u]]=++seg[0];
		top[son[u]]=top[u];
		rev[seg[0]]=son[u];
		dfs2(son[u],u);
	}
	for(int i=head[u];i!=0;i=nxt[i])
	{
		int v=to[i];
		if(!top[v])
		{
			seg[v]=++seg[0];
			top[v]=v;
			rev[seg[0]]=v;
			dfs2(v,u);
		}
	}
}
void build(int k,int l,int r)
{
	int mid=(l+r)>>1;
	if(l==r)
	{
		maxn[k]=sum[k]=num[rev[l]];
		return ;
	}
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	sum[k]=sum[k<<1]+sum[k<<1|1];
	maxn[k]=max(maxn[k<<1],maxn[k<<1|1]);
}
void fix(int k,int l,int r,int x,int w)
{
	if(l>x||x>r) return;
	if(l==r&&r==x)
	{
		sum[k]=w;
		maxn[k]=w;
		return ;
	}
	int mid=(l+r)>>1;
	if(mid>=x) fix(k<<1,l,mid,x,w);
	if(mid<x)  fix(k<<1|1,mid+1,r,x,w);
	sum[k]=sum[k<<1]+sum[k<<1|1];
	maxn[k]=max(maxn[k<<1],maxn[k<<1|1]);
}
void query(int k,int l,int r,int x,int y)
{
	if(x>r||y<l) return;
	if(x<=l&&r<=y)
	{
		summ+=sum[k];
		maxx=max(maxx,maxn[k]);
		return ;
	}
	int mid=(l+r)>>1;
	if(mid>=x) query(k<<1,l,mid,x,y);
	if(mid<y)  query(k<<1|1,mid+1,r,x,y);
}
void LCA(int x,int y)
{
	int fx=top[x],fy=top[y];
	while(fx!=fy)
	{
		if(dep[fx]<dep[fy]) swap(x,y),swap(fx,fy);
		query(1,1,seg[0],seg[fx],seg[x]);
		x=father[fx];fx=top[x];
	}
	if(dep[x]>dep[y]) swap(x,y);
	query(1,1,seg[0],seg[x],seg[y]);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b),add(b,a);
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&num[i]);
	dfs1(1,0);
	seg[0]=seg[1]=top[1]=rev[1]=1;
	dfs2(1,0);
	build(1,1,seg[0]);
	scanf("%d",&m);
	while(m--)
	{
		int u,v;
		char s[10];
		scanf("%s",s);
		scanf("%d%d",&u,&v);
		if(s[1]=='H')
			fix(1,1,seg[0],seg[u],v);
		else
		{
			summ=0;
			maxx=-0x7fffffff;
			LCA(u,v);
			if(s[1]=='M')
				printf("%d\n",maxx);
			else printf("%d\n",summ);
		}
	}
	return 0;
}
