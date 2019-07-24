#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,inf=0x3f3f3f3f;
struct edge
{
    int nxt,to;
}e[N<<1];
struct mat
{
    int d[2][2];
    mat()
    {
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                d[i][j]=0xcfcfcfcf;
    }
    friend mat operator*(const mat a,const mat b)
    {
        mat res;
        for(int k=0;k<2;k++)
            for(int i=0;i<2;i++)
                for(int j=0;j<2;j++)
                    res.d[i][j]=max(a.d[i][k]+b.d[k][j],res.d[i][j]);
        return res;
    }
};
mat sum[N<<2],val[N<<2];
int n,m,head[N],tot,f[N][2],g[N][2],a[N];
int size[N],son[N],fa[N],seg[N],rev[N],top[N],btm[N];
void add(int u,int v)
{
    e[++tot]=(edge){head[u],v},head[u]=tot;
    e[++tot]=(edge){head[v],u},head[v]=tot;
}
void dfs1(int u,int father)
{
    size[u]=1;
    fa[u]=father;
    for(int i=head[u];i!=0;i=e[i].nxt)
    {
        int v=e[i].to;
        if(v==father) continue;
        dfs1(v,u);
        size[u]+=size[v];
        if(size[v]>size[son[u]]) son[u]=v;
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
        btm[u]=btm[son[u]];
    }
    else btm[u]=u;
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
    for(int i=head[u];i!=0;i=e[i].nxt)
    {
        int v=e[i].to;
        if(v==father||v==son[u])continue;
        g[u][0]+=max(f[v][0],f[v][1]);
        g[u][1]+=f[v][0];
    }
    g[u][1]+=a[u];
    f[u][0]=g[u][0]+max(f[son[u]][0],f[son[u]][1]);
    f[u][1]=g[u][1]+f[son[u]][0];
}
void pushup(int k){sum[k]=sum[k<<1]*sum[k<<1|1];}
void build(int k,int l,int r)
{
    if(l==r)
    {
        int u=rev[l];
        val[l].d[1][1]=-inf;
        val[l].d[1][0]=g[u][1];
        val[l].d[0][0]=val[l].d[0][1]=g[u][0];
        sum[k]=val[l];
        return;
    }
    int mid=(l+r)>>1;
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
    pushup(k);
}
void modify(int k,int l,int r,int x)
{
    if(r<x||l>x) return;
    if(l==r)
    {
        sum[k]=val[l];
        return;
    }
    int mid=(l+r)>>1;
    modify(k<<1,l,mid,x);
    modify(k<<1|1,mid+1,r,x);
    pushup(k);
}
mat query(int k,int l,int r,int x,int y)
{
    if(x<=l&&r<=y) return sum[k];
    int mid=(l+r)>>1;
    if(y<=mid) return query(k<<1,l,mid,x,y);
    if(mid<x) return query(k<<1|1,mid+1,r,x,y);
    return query(k<<1,l,mid,x,y)*query(k<<1|1,mid+1,r,x,y); 
}
mat ask(int u){return query(1,1,n,seg[top[u]],seg[btm[u]]);}
void fix(int u,int w)
{
    int x=seg[u];
    val[x].d[1][0]+=w-a[u],a[u]=w;
    while(u)
    {
        mat lst=ask(u);
        modify(1,1,n,seg[u]);
        mat nxt=ask(u);
        u=fa[top[u]];
        if(!u) break;
        x=seg[u];
        val[x].d[0][0]+=max(nxt.d[0][0],nxt.d[1][0])-max(lst.d[0][0],lst.d[1][0]);
        val[x].d[0][1]=val[x].d[0][0];
        val[x].d[1][0]+=nxt.d[0][0]-lst.d[0][0];
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v);
    }
    dfs1(1,0);
    seg[0]=top[1]=rev[1]=seg[1]=1;
    dfs2(1,0);
    build(1,1,n);
    while(m--)
    {
        int u,w;
        scanf("%d%d",&u,&w);
        fix(u,w);
        mat k=ask(1);
        printf("%d\n",max(k.d[0][0],k.d[1][0]));
    }
    return 0;
}