#include<bits/stdc++.h>
using namespace std;
inline int read()
{
    int x=0;
    char c=getchar();
    while(!isdigit(c)) c=getchar();
    while(isdigit(c))
    {
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x;
}
const int maxn=5e5+5;
struct edge
{
    int nxt,to;
}e[maxn<<1];
int head[maxn],tot;
int n,m,rt,p,num[maxn];
int sum[maxn<<2],tag[maxn<<2];
int seg[maxn],rev[maxn],top[maxn];
int size[maxn],f[maxn],dep[maxn],son[maxn];
void edge_add(int u,int v)
{
    e[++tot]=(edge){head[u],v};head[u]=tot;
    e[++tot]=(edge){head[v],u};head[v]=tot;
}
void dfs(int u,int fa)
{
    f[u]=fa;
    size[u]=1;
    dep[u]=dep[fa]+1;
    for(int i=head[u];i!=0;i=e[i].nxt)
    {
        int v=e[i].to;
        if(v!=fa)
        {
            dfs(v,u);
            size[u]+=size[v];
            if(size[v]>size[son[u]]) son[u]=v;
        }
    }
}
void dfs(int u)
{
    if(son[u])
    {
        seg[son[u]]=++seg[0];
        top[son[u]]=top[u];
        rev[seg[0]]=son[u];
        dfs(son[u]);
    }
    for(int i=head[u];i!=0;i=e[i].nxt)
    {
        int v=e[i].to;
        if(!top[v])
        {
            seg[v]=++seg[0];
            top[v]=v;
            rev[seg[0]]=v;
            dfs(v);
        }
    }
}
void build(int k,int l,int r)
{
    if(l==r)
    {
        sum[k]=num[rev[l]]%p;
        return ;
    }
    int mid=(l+r)>>1;
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
    sum[k]=(sum[k<<1]+sum[k<<1|1])%p;
}
void pushdown(int k,int l,int r)
{
    if(tag[k]==0) return ;
    int w=tag[k],mid=(l+r)>>1;
    (tag[k<<1]+=w)%=p,(tag[k<<1|1]+=w)%=p;
    (sum[k<<1]+=(mid-l+1)*w)%=p,(sum[k<<1|1]+=(r-mid)*w)%=p;
    tag[k]=0;
}
void add(int k,int l,int r,int x,int y,int w)
{
    if(r<x||y<l) return;
    if(x<=l&&r<=y)
    {
        (tag[k]+=w)%=p;
        (sum[k]+=(r-l+1)*w)%=p;
        return ;
    }
    pushdown(k,l,r);
    int mid=(l+r)>>1;
    add(k<<1,l,mid,x,y,w);
    add(k<<1|1,mid+1,r,x,y,w);
    sum[k]=(sum[k<<1]+sum[k<<1|1])%p;
}
int query(int k,int l,int r,int x,int y)
{
    if(r<x||y<l) return 0;
    if(x<=l&&r<=y) return sum[k];
    pushdown(k,l,r);
    int mid=(l+r)>>1,res=0;
    (res+=query(k<<1,l,mid,x,y)+query(k<<1|1,mid+1,r,x,y))%=p;
    return res%p;
}
void LCA_add(int z,int x,int y)
{
    int fx=top[x],fy=top[y];
    while(fx!=fy)
    {
        if(dep[fx]<dep[fy]) swap(x,y),swap(fx,fy);
        add(1,1,seg[0],seg[fx],seg[x],z);
        x=f[fx];fx=top[x];
    }
    if(dep[x]>dep[y]) swap(x,y);
    add(1,1,seg[0],seg[x],seg[y],z);
}
int LCA_query(int x,int y)
{
    int fx=top[x],fy=top[y],res=0;
    while(fx!=fy)
    {
        if(dep[fx]<dep[fy]) swap(x,y),swap(fx,fy);
        (res+=query(1,1,seg[0],seg[fx],seg[x]))%=p;
        x=f[fx];fx=top[x];
    }
    if(dep[x]>dep[y]) swap(x,y);
    (res+=query(1,1,seg[0],seg[x],seg[y]))%=p;
    return res%p;
}
int main()
{
    n=read(),m=read(),rt=read(),p=read();
    for(int i=1;i<=n;i++)
        scanf("%d",&num[i]);
    for(int i=1;i<n;i++)
        edge_add(read(),read());
    dfs(rt,0);
    seg[0]=seg[rt]=1;
    rev[1]=top[rt]=rt;
    dfs(rt);
    build(1,1,seg[0]);
    for(int i=1;i<=m;i++)
    {
        int op=read();
        if(op==1) LCA_add(read(),read(),read());
        else if(op==2) printf("%d\n",LCA_query(read(),read()));
        else if(op==3)
        {
            int x=read(),z=read();
            add(1,1,seg[0],seg[x],seg[x]+size[x]-1,z);
        }
        else if(op==4)
        {
            int x=read();
            printf("%d\n",query(1,1,seg[0],seg[x],seg[x]+size[x]-1));
        }
    }
    return 0;
}