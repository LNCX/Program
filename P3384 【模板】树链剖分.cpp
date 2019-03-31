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
const int maxn=1e5+5;
struct edge
{
    int nxt,to;
}e[maxn<<1];
int n,m,rt,mod,w[maxn];
int head[maxn],tot;
int sum[maxn<<2],tag[maxn<<1];
int seg[maxn],rev[maxn],top[maxn];
int size[maxn],f[maxn],dep[maxn],son[maxn];
void edge_add(int u,int v)
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
        if(size[son[u]]<size[v]) son[u]=v;
    }
}
void dfs2(int u,int fa)
{
    if(son[u])
    {
        seg[son[u]]=++seg[0];
        top[son[u]]=top[u];
        rev[seg[0]]=son[u];
        dfs2(son[u],u);
    }
    for(int i=head[u];i!=0;i=e[i].nxt)
    {
        int v=e[i].to;
        if(!top[v])
        {
            seg[v]=++seg[0];
            top[v]=v;
            rev[seg[0]]=v;
        }
    }
}

int main()
{
    n=read(),m=read(),rt=read(),mod=read();
    for(int i=1;i<=n;i++)
        scanf("%d",&w[i]);
    for(int i=1;i<n;i++)
        edge_add(read(),read());
    dfs1(rt,0);
    seg[0]=seg[rt]=1;
    rev[1]=top[rt]=rt;
    dfs2();
    for(int i=1;i<=m;i++)
    {
        int op=read(),x,y,z;
        if(op==1)
        {
            x=read(),y=read(),z=read();
        }
    }
    return 0;
}