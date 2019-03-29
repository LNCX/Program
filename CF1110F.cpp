#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e5+5;
const ll oo=1e17;
int n,m;
struct edge
{
    int nxt,to,w;
}e[maxn<<1];
ll minx[maxn<<2],dis[maxn],num[maxn],tag[maxn<<2];
int head[maxn],tot,son[maxn],size[maxn];
void add(int u,int v,int w)
{
    e[++tot]=(edge){head[u],v,w};
    head[u]=tot;
}
void dfs(int u,int fa)
{
    size[u]=1;
    for(int i=head[u];i!=0;i=e[i].nxt)
    {
        int v=e[i].to;
        if(v==fa) continue;
        dis[v]=dis[u]+e[i].w;
        dfs(v,u);
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
void print()
{
    for(int i=1;i<=9;i++)
    {
        cout<<son[i]<<" ";
    }
    puts("");
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
    for(int i=1;i<=(n<<2);i++)
        minx[i]=oo;
    dfs(1,0);
    build(1,1,n);
    //print();
    while(m--)
    {
        int u,l,r;
        scanf("%d%d%d",&u,&l,&r);
        add(1,1,n,1,n,dis[u]);
        //print();
        add(1,1,n,u,son[u],-(dis[u]<<1));
        //print();
        printf("%lld\n",query(1,1,n,l,r));
        //print();
        add(1,1,n,u,son[u],(dis[u])<<1);
        add(1,1,n,1,n,-dis[u]);
    }
    return 0;
}