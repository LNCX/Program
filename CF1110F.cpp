#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e5+5;
const ll oo=0x7ffffffffffffff;
int n,m;
struct edge
{
    int nxt,to,w;
}e[maxn<<1];
ll minx[maxn],dis[maxn],num[maxn],tag[maxn];
int head[maxn],tot,son[maxn],size[maxn];
void add(int u,int v,int w)
{
    e[++tot]=(edge){head[u],v,w};
    head[u]=tot;
}
void dfs1(int u,int fa)
{
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
    if(size[u]==1) num[u]=dis[u],son[u]=u;
    else num[u]=oo;
}
void build(int k,int l,int r)
{
    if(l==r)
    {
        minx[k]=num[k];
        return ;
    }
    int mid=(l+r)>>1;
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
    minx[k]=min(minx[k<<1],minx[k<<1|1]);
}
void down(int k,int l,int r)
{

}
void add(int k,int l,int r,int x,int y,ll w)
{
    if(l==r)
    {
        
    }
}
int query(int k,int l,int r,int x,int y)
{

}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=2;i<=n;i++)
    {
        int v,w;
        scanf("%d%d",&v,&w);
        add(i,v,w),add(v,i,w);        
    }
    dfs1(1,0);
    build(1,1,n);
    while(m--)
    {
        int u,l,r;
        scanf("%d%d%d",&u,&l,&r);
        if(size[u]==1) puts("0");
        else 
        {
            add(1,1,n,son[u]-size[u]+2,son[u],-dis[u]);
            printf("%lld\n",query(1,1,n,l,r));
            add(1,1,n,son[u]-size[u]+2,son[u],dis[u]);
        }
    }
    return 0;
}