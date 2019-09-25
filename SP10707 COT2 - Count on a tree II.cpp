#include<bits/stdc++.h>
using namespace std;
const int N=4e4+5,M=1e5+5;
map<int,int>ma;
int n,m,dep[N],f[N][20],block,ans[M],now,w[N],cnt[N],num;
int head[N],tot,dfstime,st[N<<1],ed[N<<1],a[N<<1],used[N<<1];
struct edge
{
    int nxt,to;
}e[N<<1];
struct node
{
    int l,r,lca,id;
    friend  bool operator<(const node &a,const node &b)
    {
        return (a.l/block)^(b.l/block)?a.l<b.l:(((a.l/block)&1)?a.r<b.r:a.r>b.r);
    }
}q[M];
void edge_add(int u,int v)
{
    e[++tot]=(edge){head[u],v},head[u]=tot;
    e[++tot]=(edge){head[v],u},head[v]=tot;
}
void dfs(int u,int fa)
{
    f[u][0]=fa;
    dep[u]=dep[fa]+1;
    a[st[u]=++dfstime]=u;
    for(int i=1;i<=19;i++)
        f[u][i]=f[f[u][i-1]][i-1];
    for(int i=head[u];i!=0;i=e[i].nxt)
    {
        int v=e[i].to;
        if(v==fa) continue;
        dfs(v,u);
    }
    a[ed[u]=++dfstime]=u;
}
int lca(int x,int y)
{
    if(dep[x]<dep[y]) swap(x,y);
    for(int i=19;i>=0;i--)
        if(dep[f[x][i]]>=dep[y])
            x=f[x][i];
    if(x==y) return x;
    for(int i=19;i>=0;i--)
        if(f[x][i]!=f[y][i])
            x=f[x][i],y=f[y][i];
    return f[x][0];
}
void add(int x){if(++cnt[x]==1) now++;}
void del(int x){if(--cnt[x]==0) now--;}
void fix(int x){used[x]?del(w[x]):add(w[x]);used[x]^=1;}
void moque()
{
    sort(q+1,q+1+m);
    int l=1,r=0;now=0;
    for(int i=1;i<=m;i++)
    {
        int ql=q[i].l,qr=q[i].r;
        while(ql<l) fix(a[--l]);
        while(ql>l) fix(a[l++]);
        while(qr<r) fix(a[r--]);
        while(qr>r) fix(a[++r]);
        if(q[i].lca) fix(q[i].lca);
        ans[q[i].id]=now;
        if(q[i].lca) fix(q[i].lca);
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        if(ma[x]) w[i]=ma[x];
        else w[i]=ma[x]=++num;
    }
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        edge_add(u,v);
    }
    dfs(1,0);
    block=sqrt(2*n);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        if(st[u]>st[v]) swap(u,v);
        int x=lca(u,v);
        if(x==u) q[i]=(node){st[u],st[v],0,i};
        else q[i]=node{ed[u],st[v],x,i};
    }
    moque();
    for(int i=1;i<=m;i++)
        printf("%d\n",ans[i]);
    return 0;
}