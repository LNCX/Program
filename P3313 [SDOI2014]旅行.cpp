#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,q,rt,anss,ansm;
int w[N],c[N],head[N],tot;
int size[N],dep[N],f[N],son[N],seg[N],top[N];
int maxx[N<<5],sum[N<<5],tag[N<<5],ch[N<<5][2],t[N<<5];
struct edge
{
    int nxt,to;
}e[N<<1];
void add(int u,int v)
{
    e[++tot]=(edge){head[u],v};head[u]=tot;
    e[++tot]=(edge){head[v],u};head[v]=tot;
}
void dfs1(int u,int fa)
{
    f[u]=fa;
    size[u]=1;
    dep[u]=dep[fa]+1;
    for(int i=head[u];i!=0;i=e[i].nxt)
    {
        int v=e[i].to;
        if(v==fa) continue;
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
        dfs2(son[u]);
    }
    for(int i=head[u];i!=0;i=e[i].nxt)
    {
        int v=e[i].to;
        if(!top[v])
        {
            seg[v]=++seg[0];
            top[v]=v;
            dfs2(v);
        }
    }
}
void pushup(int k)
{
    maxx[k]=max(maxx[ch[k][0]],maxx[ch[k][1]]);
    sum[k]=sum[ch[k][0]]+sum[ch[k][1]];
}
void pushdown(int k)
{
    maxx[k]=sum[k]=ch[k][0]=ch[k][1]=0;
}
void insert(int &k,int l,int r,int x,int w)
{
    if(!k) k=++rt;
    if(l==r)
    {
        sum[k]=maxx[k]=w;
        return ;
    }
    int mid=(l+r)>>1;
    if(x<=mid) insert(ch[k][0],l,mid,x,w);
    else insert(ch[k][1],mid+1,r,x,w);
    pushup(k);
}
void remove(int &k,int l,int r,int x)
{
    if(l==r)
    {
        pushdown(k),k=0;
        return;
    }
    int mid=(l+r)>>1;
    if(x<=mid) remove(ch[k][0],l,mid,x);
    else remove(ch[k][1],mid+1,r,x);
    pushup(k);
    if(ch[k][1]==0&&ch[k][0]==0)
    {
        pushdown(k),k=0;
        return ;
    }
}
void changec(int x,int y)
{
    remove(t[c[x]],1,n,seg[x]);
    insert(t[c[x]=y],1,n,seg[x],w[x]);
}
void changew(int x,int y)
{
    w[x]=y;
    insert(t[c[x]],1,n,seg[x],w[x]);
}
void query(int k,int l,int r,int x,int y)
{
    if(l>y||r<x) return;
    if(x<=l&&y>=r)
    {
        anss+=sum[k];
        ansm=max(ansm,maxx[k]);
        return;
    }
    int mid=(l+r)>>1;
    query(ch[k][0],l,mid,x,y);
    query(ch[k][1],mid+1,r,x,y);
}
void LCA_query(int x,int y)
{
    int fx=top[x],fy=top[y],k=t[c[x]];
    anss=ansm=0;
    while(fx!=fy)
    {
        if(dep[fx]<dep[fy]) swap(x,y),swap(fx,fy);
        query(k,1,n,seg[fx],seg[x]);
        x=f[fx],fx=top[x];
    }
    if(dep[x]>dep[y]) swap(x,y);
    query(k,1,n,seg[x],seg[y]);
}
void print(int k)
{
    if(!k) return;
    printf("%d %d %d %d %d\n",k,ch[k][0],ch[k][1],sum[k],maxx[k]);
    print(ch[k][0]),print(ch[k][1]);
}
int main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&w[i],&c[i]);
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v);
    }
    dfs1(1,0);
    seg[0]=seg[1]=top[1]=1;
    dfs2(1);
    for(int i=1;i<=n;i++)
        insert(t[c[i]],1,n,seg[i],w[i]);
    while(q--)
    {
        char s[2];
        int x,y;
        scanf("%s%d%d",s,&x,&y);
        if(s[0]=='C')
        {
            if(s[1]=='C') changec(x,y);
            else changew(x,y);
        }
        else
        {
            LCA_query(x,y);
            if(s[1]=='S') printf("%d\n",anss);
            else printf("%d\n",ansm);
        }
    }
    return 0;
}