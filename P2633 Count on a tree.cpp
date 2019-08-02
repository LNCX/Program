#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,q,rt,a[N],b[N],dep[N],ans;
int t[N],ch[N<<5][2],f[N][20],sum[N<<5];
vector<int>e[N];
void update(int pre,int &k,int l,int r,int x)
{
    if(l>x||r<x) return ;
    k=++rt;
    ch[k][0]=ch[pre][0],ch[k][1]=ch[pre][1],sum[k]=sum[pre]+1;
    if(l==r) return;
    int mid=(l+r)>>1;
    update(ch[pre][0],ch[k][0],l,mid,x);
    update(ch[pre][1],ch[k][1],mid+1,r,x);
}
void dfs(int u,int fa)
{
    f[u][0]=fa;
    dep[u]=dep[fa]+1;
    for(int i=1;i<=17;i++)
        f[u][i]=f[f[u][i-1]][i-1];
    int x=lower_bound(b+1,b+1+m,a[u])-b;
    update(t[fa],t[u],1,m,x);
    for(auto v:e[u])
    {
        if(v==fa) continue;
        dfs(v,u);
    }
}
int lca(int x,int y)
{
    if(dep[x]<dep[y]) swap(x,y);
    for(int i=17;i>=0;i--)
    {
        if(dep[f[x][i]]>=dep[y])
            x=f[x][i];
        if(x==y) return x;
    }
    for(int i=17;i>=0;i--)
        if(f[x][i]!=f[y][i])
            x=f[x][i],y=f[y][i];
    return f[x][0];
}
int query(int u,int v,int x,int fx,int l,int r,int k)
{
    if(l==r) return l;
    int w=sum[ch[u][0]]+sum[ch[v][0]]-sum[ch[x][0]]-sum[ch[fx][0]];
    int mid=(l+r)>>1;
    if(k<=w) return query(ch[u][0],ch[v][0],ch[x][0],ch[fx][0],l,mid,k);
    else return query(ch[u][1],ch[v][1],ch[x][1],ch[fx][1],mid+1,r,k-w);
}
int main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        b[i]=a[i];
    }
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].push_back(v),e[v].push_back(u);
    }
    sort(b+1,b+1+n);
    m=unique(b+1,b+1+n)-b-1;
    dfs(1,0);
    while(q--)
    {
        int u,v,k;
        scanf("%d%d%d",&u,&v,&k);
        u^=ans;
        int x=lca(u,v);
        ans=b[query(t[u],t[v],t[x],t[f[x][0]],1,m,k)];
        printf("%d\n",ans);
    }
    return 0;
}