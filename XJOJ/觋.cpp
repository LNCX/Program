#pragma  GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=6e5+5;
ll a[N];
vector<int>e[N];
int dep[N],f[N][20];
void dfs(int u,int fa)
{
    dep[u]=dep[fa]+1;
    f[u][0]=fa; 
    for(int i=1;i<=19;i++)
        f[u][i]=f[f[u][i-1]][i-1];
    for(auto v:e[u])
    {
        if(v==fa) continue;
        dfs(v,u);
    }
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
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        e[u].push_back(v),e[v].push_back(u);
    }
    dfs(1,0);
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        int x=lca(u,v),len=-2*dep[x]+dep[u]+dep[v],t=0;
        ll ans=(dep[u]-dep[x])|a[x];
        while(u!=x)
        {
            ans+=(ll)(t|a[u]);
            t++,u=f[u][0];
        }
        while(v!=x)
        {
            ans+=(ll)(len|a[v]);
            len--,v=f[v][0];
        }
        printf("%lld\n",ans);
    }
    return 0;
}