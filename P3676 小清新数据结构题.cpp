#include<bits/stdc++.h>
using namespace std;
inline int read()
{
    int x=0;
    bool f=true;
    char c=getchar();
    while(!isdigit(c))
    {
        if(c=='-') f=false;
        c=getchar();
    }
    while(isdigit(c))
    {
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return f?x:-x;
}
typedef long long ll;
const int N=2e5+5;
struct edge
{
    int nxt,to;
}e[N<<1];
int head[N],tot,n,q;
int f[N],dep[N],son[N];
int seg[N],rev[N],top[N];
ll a[N],sum[N<<2],tag[N<<2],sum2[N<<2],w[N],size[N],a0;
inline void edge_add(int u,int v)
{
    e[++tot]=(edge){head[u],v};
    head[u]=tot;
    e[++tot]=(edge){head[v],u};
    head[v]=tot;
}
inline void dfs(int u,int fa)
{
    f[u]=fa;
    size[u]=1;
    a[u]=w[u];
    dep[u]=dep[fa]+1;
    for(int i=head[u];i!=0;i=e[i].nxt)
    {
        int v=e[i].to;
        if(v==fa) continue;
        dfs(v,u);
        a[u]+=a[v];
        size[u]+=size[v];
        if(size[v]>size[son[u]]) son[u]=v;
    }
}
inline void dfs(int u)
{
    if(son[u])
    {
        seg[son[u]]=++seg[0];
        top[son[u]]=top[u];
        rev[seg[0]]=son[u];
        dfs(son[u]);
    }
    for(int i=head[u];i!=0;i=e[i].nxt)
    {
        int v=e[i].to;
        if(!top[v])
        {
            seg[v]=++seg[0];
            top[v]=v;
            rev[seg[0]]=v;
            dfs(v);
        }
    }
}
inline void build(int k,int l,int r)
{
    if(l==r)
    {
        sum[k]=a[rev[l]];
        sum2[k]=sum[k]*sum[k];
        return ;
    }
    int mid=(l+r)>>1;
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
    sum[k]=(sum[k<<1]+sum[k<<1|1]);
    sum2[k]=(sum2[k<<1]+sum2[k<<1|1]);
}
inline void pushdown(int k,int l,int r)
{
    if(tag[k]==0) return ;
    int a=tag[k],mid=(l+r)>>1;
    (tag[k<<1]+=a),(tag[k<<1|1]+=a);
    sum2[k<<1]+=2*sum[k<<1]*a+(mid-l+1)*a*a,sum2[k<<1|1]+=2*sum[k<<1|1]*a+(r-mid)*a*a,
    sum[k<<1]+=(mid-l+1)*a,sum[k<<1|1]+=(r-mid)*a;
    tag[k]=0;
}
inline void add(int k,int l,int r,int x,int y,ll z)
{
    if(r<x||y<l) return;
    if(x<=l&&r<=y)
    {
        (tag[k]+=z);
        (sum2[k]+=2*sum[k]*z+(r-l+1)*z*z);
        (sum[k]+=(r-l+1)*z);
        return ;
    }
    pushdown(k,l,r);
    int mid=(l+r)>>1;
    add(k<<1,l,mid,x,y,z);
    add(k<<1|1,mid+1,r,x,y,z);
    sum[k]=(sum[k<<1]+sum[k<<1|1]);
    sum2[k]=(sum2[k<<1]+sum2[k<<1|1]);
}
inline void query(int k,int l,int r,int x,int y,ll &ans,ll &len)
{
    if(r<x||y<l) return;
    if(x<=l&&r<=y)
    {
        ans+=sum2[k];
        len+=sum[k];
        return ;
    }
    pushdown(k,l,r);
    int mid=(l+r)>>1;
    query(k<<1,l,mid,x,y,ans,len);
    query(k<<1|1,mid+1,r,x,y,ans,len);
}
inline void LCA_add(int x,int y,ll z)
{
    int fx=top[x],fy=top[y];
    while(fx!=fy)
    {
        if(dep[fx]<dep[fy]) swap(x,y),swap(fx,fy);
        add(1,1,seg[0],seg[fx],seg[x],z);
        x=f[fx];fx=top[x];
    }
    if(dep[x]>dep[y]) swap(x,y);
    add(1,1,seg[0],seg[x],seg[y],z);
    // for(int i=1;i<=7;i++)
    //     printf("%lld %lld %lld\n",sum[i],sum2[i],tag[i]);
    // puts("\n");
}
inline void LCA_query(int x)
{
    ll ans=0,len=0,tmp=0,k=dep[x];
    query(1,1,n,1,n,ans,tmp);
    while(top[x]!=1)
    {
        int fx=top[x];
        query(1,1,n,seg[fx],seg[x],tmp,len);
        x=f[fx];
    }
    query(1,1,n,1,seg[x],tmp,len);
    len-=a0;
    // for(int i=1;i<=7;i++)
    //     printf("%lld %lld %lld\n",sum[i],sum2[i],tag[i]);
    // puts("\n");
    printf("%lld\n",ans+(k-1)*a0*a0-2*a0*len);
}
int main()
{
    n=read(),q=read();
    for(int i=1;i<n;i++)
        edge_add(read(),read());
    for(int i=1;i<=n;i++)
        w[i]=read();
    dfs(1,0);
    seg[0]=seg[1]=rev[1]=top[1]=1,a0=a[1];
    dfs(1);
    build(1,1,n);
    // for(int i=1;i<=7;i++)
    //     printf("%lld %lld %lld\n",sum[i],sum2[i],tag[i]);
    // puts("\n");
    while(q--)
    {
        int op=read(),x=read();
        if(op==1)
        {
            int y=read();
            LCA_add(1,x,y-w[x]);
            a0+=y-w[x],w[x]=y;
        }
        else LCA_query(x);
    }
    return 0;
}