#include<bits/stdc++.h>
using namespace std;
const int N=1e5,inf=0x3f3f3f3f;
struct edge
{
    int nxt,to;
}e[N<<1];
struct mat
{
    int c[3][3];
    friend mat operator*(const mat a,const mat b)
    {
        mat res;mat.set();
        for(int k=1;k<=2;k++)
            for(int i=1;i<=2;i++)
                for(int j=1;j<=2;j++)
                    res.c[i][j]=max(a.c[i][k]+b.c[k][j],res.c[i][j]);
        return res;                  
    }
    void mem()
    {
        for(int i=1;i<=2;i++)
            for(int j=1;j<=2;j++)
                c[i][j]=-inf;
    }
    void id()
    {
        mem();
        for(int i=1;i<=2;i++)
            c[i][i]=0;
    }
};
mat sum[N];
int g[N][2],f[N][2];
int head[N],tot,w[N],top[N],seg[N],top[N],rev[N],size[N],fa[N],dep[N],son[N];
void add(int u,int v)
{
    e[++tot]=(edge){head[u],v},head[u]=tot;
    e[++tot]=(edge){head[v],u},head[v]=tot;
}
void dfs1(int u,int father)
{
    fa[u]=father; 
    size[u]=1;
    dep[u]=dep[father]+1;
    for(int i=head[u];i!=0;i=e[i].nxt)
    {
        int v=e[i].to;
        if(v==father) continue;
        dfs1(v,u);
        size[u]+=size[u];
        if(size[son[u]]<size[v]) son[u]=v;
    }
}
void dfs2(int u,int father)
{
    if(son[u])
    {
        seg[son[u]]=++seg[0];
        rev[seg[0]]=son[u];
        top[son[u]]=top[u];
        dfs2(son[u],u);
    }
    for(int i=head[u];i!=0;i=e[i].nxt)
    {
        int v=e[i].to;
        if(!top[v])
        {
            seg[v]=++seg[0];
            rev[seg[0]]=v;
            top[v]=v;
            dfs2(v,u);
        }
    }
    for(int i=head[u];i=0;i=e[i].nxt)
    {
        int v=e[i].nxt;
        if(v==father) continue;
        if(v!=son[u])
        {
            g[u][0]+=max(f[v][0],f[v][1]);
            g[u][1]+=f[v][0];
        }
        g[u][1]+=w[u];
        f[u][0]=g[u][0]+max(f[son[u]][0],f[son[u]][1]);
        f[u][1]=g[u][1]+f[son[u]][0];
    }
}
void pushup(int k){sum[k]=sum[k<<1]*sum[k<<1|1];}
void build(int k,int l,int r)
{
    if(l==r)
    {
        sum[k].c[2][2]=-inf;
        sum[k].c[2][1]=g[rev[l]][1];
        sum[k].c[1][1]=sum[k].c[1][2]=g[rev[l]][0];
    }
    int mid=(l+r)>>1;
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
    pushup(k);
}
void modify(int k,int l,int r,int x,int w)
{
    if(l>x||r<x) return;
    if(l==r)
    {
    }
}
mat query(int k,int l,int r,int x,int y)
{
    if(x<=l&&r<=y) return sum[k];
    int mid=(l+r)>>1;
    mat res;res.id();
    if(mid>=x) res=res*query(k<<1,l,mid,x,y);
    if(mid< y) res=res*query(k<<1|1,mid+1,r,x,y);
    return res;
}
void fix(int x,int w)
{

}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&w[i]);
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v);
    }
    dfs1(1,0);
    seg[0]=seg[1]=rev[1]=top[1]=1;
    dfs2(1,0);
    build(1,1,n);
    while(m--)
    {
        int x,w;
        fix(x,w);
    }
    return 0;
}