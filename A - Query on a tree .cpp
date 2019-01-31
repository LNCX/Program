#include<stdio.h>
#include<string.h>
using namespace std;
const int N=1e6+5;
int n,maxx;
int seg[N],rev[N],size[N],son[N],top[N];
int num[N],father[N],dep[N],maxn[N<<2];
int e_num,head[N<<2],to[N<<2],nxt[N<<2],w[N<<2];
void clear()
{
    e_num=0;
    memset(head,0,sizeof(head));
    memset(size,0,sizeof(size));
    memset(son,0,sizeof(son));
    memset(nxt,0,sizeof(nxt));
    memset(top,0,sizeof(top));
    memset(rev,0,sizeof(rev));
    memset(seg,0,sizeof(seg));
    memset(num,0,sizeof(num));
    memset(father,0,sizeof(father));
    memset(dep,0,sizeof(dep));
}
void swap(int &a,int &b)
{
    int t=a;a=b;b=t;
}
int max(int a,int b)
{
    return a>b?a:b;
}
void add(int u,int v,int z)
{
    nxt[++e_num]=head[u];
    to[e_num]=v;
    w[e_num]=z;
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
            num[v]=w[i];
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
        maxn[k]=num[rev[l]];
        return ;
    }
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
    maxn[k]=max(maxn[k<<1],maxn[k<<1|1]);
}
void fix(int k,int l,int r,int x,int w)
{
    if(l>x||x>r) return;
    if(l==r&&r==x)
    {
        maxn[k]=w;
        return ;
    }
    int mid=(l+r)>>1;
    if(mid>=x) fix(k<<1,l,mid,x,w);
    if(mid<x)  fix(k<<1|1,mid+1,r,x,w);
    maxn[k]=max(maxn[k<<1],maxn[k<<1|1]);
}
void query(int k,int l,int r,int x,int y)
{
    if(x>r||y<l) return;
    if(x<=l&&r<=y)
    {
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
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        scanf("%d",&n);
        clear();
        for(int i=1;i<n;i++)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            add(a,b,c),add(b,a,c);
        }
        dfs1(1,0);
        seg[0]=seg[1]=top[1]=rev[1]=1;
        dfs2(1,0);
        build(1,1,seg[0]);
        while(1)
        {
            int u,v;
            char s[10];
            scanf("%s",s);
            if(s[0]=='D') break;
            scanf("%d%d",&u,&v);
            if(s[0]=='C')
                fix(1,1,seg[0],seg[u],v);
            else if(s[0]=='Q')
            {
                maxx=-0x7fffffff;
                LCA(u,v);
                printf("%d\n",maxx);
            }
        }
        puts("");
    }
    return 0;
}