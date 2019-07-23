#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,inf=0x3f3f3f3f;
struct edge
{
    int nxt,to;
}e[N<<1];
struct mat
{
    int d[3][3];
    friend mat operator*(const mat a,const mat b)
    {
        mat c;c.clear();               
        for(int k=1;k<=2;k++)
            for(int i=1;i<=2;i++)
                for(int j=1;j<=2;j++)
                    c.d[i][j]=max(a.d[i][k]+b.d[k][j],c.d[i][j]);
        return c;
    }
    void clear()
    {
        for(int i=1;i<=2;i++)   
            for(int j=1;j<=2;j++)
                d[i][j]=-inf;
    }
    bool check()
    {
        for(int i=1;i<=2;i++)
            for(int j=1;j<=2;j++)
                if(d[i][j]!=-inf)
                    return false;
        return true;
    }
    mat()
    {
        for(int i=1;i<=2;i++)   
            for(int j=1;j<=2;j++)
                d[i][j]=-inf;
    }
};
mat sum[N<<2],val[N];
int head[N],tot,a[N],n,m,f[N][2],g[N][2];
int seg[N],rev[N],dep[N],size[N],son[N],top[N],bot[N],fa[N];
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
void dfs2(int u)
{
    if(son[u])
    {
        seg[son[u]]=++seg[0];
        top[son[u]]=top[u];
        rev[seg[0]]=son[u];
        dfs2(son[u]);
        bot[u]=bot[son[u]];
    }
    else bot[u]=u;
    for(int i=head[u];i!=0;i=e[i].nxt)
    {
        int v=e[i].to;
        if(!top[v])
        {
            seg[v]=++seg[0];
            rev[seg[0]]=v;
            top[v]=v;
            dfs2(v);
        }
    }
}
void dfs3(int u,int father)
{
    //cerr<<u<<endl;
    for(int i=head[u];i!=0;i=e[i].nxt)
    {
        int v=e[i].to;
        if(v==father) continue;
        dfs3(v,u);
        if(v!=son[u])
        {
            g[u][0]+=max(f[v][0],f[v][1]);
            g[u][1]+=f[v][0];
        }
    }
    g[u][1]+=a[u];
    f[u][1]=g[u][1]+f[son[u]][0];
    f[u][0]=g[u][0]+max(f[son[u]][0],f[son[u]][1]);
}
void pushup(int k){sum[k]=sum[k<<1]*sum[k<<1|1];}
void build(int k,int l,int r)
{
    
    if(l==r)
    {
        int u=rev[l];
        val[l].d[1][1]=val[l].d[1][2]=g[u][0];
        val[l].d[2][1]=g[u][1];
        val[l].d[2][2]=-inf;
        sum[k]=val[l];
        return;
    }
    int mid=(l+r)>>1;
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
    pushup(k);
}
mat query(int k,int l,int r,int x,int y)
{
    if(x<=l&&r<=y){return sum[k];}
    int mid=(l+r)>>1;
    mat res;
    if(mid>=x) res=query(k<<1,l,mid,x,y);
    if(mid< y) 
    {
        if(res.check()) res=query(k<<1|1,mid+1,r,x,y);
        else res=res*query(k<<1|1,mid+1,r,x,y);
    }
    return res;
}
mat ask(int u)
{return query(1,1,n,seg[top[u]],seg[bot[u]]);}
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
void fix(int u,int w)
{
    val[u].d[2][1]=w,a[u]=w;
    while(u)
    {
        mat lst=ask(u);
        modify(1,1,n,u);
        mat nxt=ask(u);
        u=fa[top[u]];
        int fv0=max(lst.d[1][1],lst.d[1][2]),fv1=max(lst.d[2][1],lst.d[2][2]);
        int _fv0=max(nxt.d[1][1],nxt.d[1][2]),_fv1=max(nxt.d[2][1],nxt.d[2][2]);
        val[u].d[1][1]+=max(_fv0,_fv1)-max(fv0,fv1);
        val[u].d[1][2]=val[u].d[1][1];
        val[u].d[2][1]+=_fv0-fv0;
    }
}
#ifdef DEBUG
    void print()
    {
        for(int i=1;i<=n;i++)
            printf("%d %d\n",f[i][0],f[i][1]);
    }
#endif
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
    seg[0]=seg[1]=rev[1]=top[1]=1;
    dfs2(1);
    dfs3(1,0);
    build(1,1,n);
    while(m--)
    {
        int u,w;
        scanf("%d%d",&u,&w);
        fix(u,w);
        mat k=sum[1];
        printf("%d\n",max(max(k.d[1][1],k.d[1][2]),max(k.d[2][1],k.d[2][2])) );
    }
    #ifdef DEBUG
        print();
    #endif
    return 0;
}
