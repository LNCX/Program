#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
const ll N=5e5+5,oo=1ll<<60;
int n,m,tot,head[N],size[N],son[N],L[N],R[N];
ll dis[N],num[N],minx[N<<2],tag[N<<2],ans[N];
struct edge
{
    int nxt,to,w;
}e[N<<1];
vector<int>q[N];
void add_edge(int w,int v,int u)
{
    e[++tot]=(edge){head[u],v,w};
    head[u]=tot;
    e[++tot]=(edge){head[v],u,w};
    head[v]=tot;
}
void dfs1(int u,int fa)
{
    son[u]=u;
    size[u]=1;
    for(int i=head[u];i!=0;i=e[i].nxt)
    {
        int v=e[i].to;
        if(v==fa) continue;
        dis[v]=dis[u]+e[i].w;
        dfs1(v,u);
        son[u]=max(son[u],son[v]);
        size[u]+=size[v];
    }
    if(size[u]==1) num[u]=dis[u];
    else num[u]=oo;
}
void build(int k,int l,int r)
{
    if(l==r)
    {
        minx[k]=num[l];
        return ;
    }
    int mid=(l+r)>>1;
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
    minx[k]=min(minx[k<<1],minx[k<<1|1]);
}
void pushdown(int k)
{
    if(!tag[k]) return ;
    minx[k<<1]+=tag[k],minx[k<<1|1]+=tag[k];
    tag[k<<1]+=tag[k],tag[k<<1|1]+=tag[k];
    tag[k]=0;
}
void add(int k,int l,int r,int x,int y,ll w)
{
    if(x<=l&&r<=y)
    {
        tag[k]+=w;
        minx[k]+=w;
        return;
    }
    pushdown(k);
    int mid=(l+r)>>1;
    if(x<=mid) add(k<<1,l,mid,x,y,w);
    if(y> mid) add(k<<1|1,mid+1,r,x,y,w);
    minx[k]=min(minx[k<<1],minx[k<<1|1]);
}
ll query(int k,int l,int r,int x,int y)
{
    if(x<=l&&r<=y) return minx[k];
    pushdown(k);
    int mid=(l+r)>>1;
    ll res=oo;
    if(x<=mid) res=min(res,query(k<<1,l,mid,x,y));
    if(y> mid) res=min(res,query(k<<1|1,mid+1,r,x,y));
    return res;
}
void dfs2(int u,int fa)
{
    for(int i:q[u])
        ans[i]=query(1,1,n,L[i],R[i]);
    for(int i=head[u];i!=0;i=e[i].nxt)
    {
        int v=e[i].to,w=e[i].w;
        if(v==fa) continue;
        add(1,1,n,1,n,w);
        add(1,1,n,v,son[v],-w-w);
        dfs2(v,u);
        add(1,1,n,1,n,-w);
        add(1,1,n,v,son[v],w+w);
    }
}
int main()
{
    n=read(),m=read();
    for(int i=2;i<=n;i++)
        add_edge(read(),i,read());
    for(int i=1;i<=m;i++)
    {
        int u=read();
        L[i]=read(),R[i]=read();
        q[u].push_back(i);
    }
    dfs1(1,0);
    build(1,1,n);
    dfs2(1,0);
    for(int i=1;i<=m;i++)
        printf("%lld\n",ans[i]);
    return 0;
}