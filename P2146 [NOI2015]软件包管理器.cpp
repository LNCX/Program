#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m;
bool tag[N<<2],vis[N<<2];
int seg[N],rev[N],sum[N<<2];
int head[N],to[N<<1],nxt[N<<1],edge_sum;
int dep[N],fa[N],size[N],son[N],top[N];
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
void down(int k,int l,int r)
{
    if(!vis[k])return;
    int mid=l+r>>1;
    sum[k<<1]=tag[k]*(mid-l+1);
	sum[k<<1|1]=tag[k]*(r-mid);
    tag[k<<1]=tag[k<<1|1]=tag[k];
	vis[k<<1]=vis[k<<1|1]=true;
	vis[k]=false;
}
void Add(int k,int l,int r,int x,int y,bool val)
{
    if(x<=l&&r<=y)
	{
		sum[k]=val*(r-l+1);
		tag[k]=val;vis[k]=true;
		return;
	}
    int mid=l+r>>1;
	down(k,l,r);
    if(x<=mid) Add(k<<1,l,mid,x,y,val);
    if(y>mid ) Add(k<<1|1,mid+1,r,x,y,val);
    sum[k]=sum[k<<1]+sum[k<<1|1];
}
int query(int k,int l,int r,int x,int y)
{
    if(x<=l&&r<=y)return sum[k];
    int mid=l+r>>1,ans=0;
	down(k,l,r);
    if(x<=mid)ans+=query(k<<1,l,mid,x,y);
    if(y>mid)ans+=query(k<<1|1,mid+1,r,x,y);
    return ans;
}
int ins(int x)
{
    int fx=top[x],k=x,ans=0;
    while(fx!=1)
    {
        ans+=query(1,1,seg[0],seg[fx],seg[x]);
        Add(1,1,seg[0],seg[fx],seg[x],1);
        x=fa[fx],fx=top[x];
    }
    ans+=query(1,1,seg[0],1,seg[x]);
    Add(1,1,seg[0],1,seg[x],1);
    return dep[k]-ans;
}
int del(int x)
{
    int ans=0;
    ans+=query(1,1,seg[0],seg[x],seg[x]+size[x]-1);
    Add(1,1,seg[0],seg[x],seg[x]+size[x]-1,0);
    return ans;
}
signed main()
{
    scanf("%d",&n);
    for(int i=2;i<=n;++i)
    {
        scanf("%d",fa+i);++fa[i];
        edge_add(fa[i],i),edge_add(i,fa[i]);
    }
    dep[1]=rev[1]=seg[0]=seg[1]=top[1]=1;
    dfs1(1,0);
	dfs2(1);
    scanf("%d",&m);
    while(m--)
    {
		int x;
		char op[10];
        scanf("%s%d",op,&x);++x;
        printf("%d\n",op[0]=='i'?ins(x):del(x));
    }
}