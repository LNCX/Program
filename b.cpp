#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e4+5;
ll w[N],p[N];
vector<int>e[N];
int f[N][20],dep[N];
void insert(ll x)
{
    for(int i=60;i>=0;i--)
    {
        if(!(x>>i)) continue;
        if(!p[i]) {p[i]=x;break;}
        else x^=p[i];
    }
}
void dfs(int u,int fa)
{
    f[u][0]=fa;
    dep[u]=dep[fa]+1;
    for(int i=1;i<=15;i++)
        f[u][i]=f[f[u][i-1]][i-1];
    for(auto v:e[u])
    {
        if(v==fa) continue;
        dfs(v,u);
    }
}
int lca(int x,int y)
{
    if(dep[x]<dep[y])swap(x,y);
    for(int i=15;i>=0;i--)
        if(dep[f[x][i]]>=dep[y])
            x=f[x][i];
    if(x==y) return x;
    for(int i=15;i>=0;i--)
        if(f[x][i]!=f[y][i])
            x=f[x][i],y=f[y][i];
    return f[x][0];
}
int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
        scanf("%lld",&w[i]);
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].push_back(v),e[v].push_back(u);
    }
    dfs(1,0);
    while(q--)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        memset(p,0,sizeof(p));
        int x=lca(u,v);
        while(u!=x)
        {
            insert(w[u]);
            u=f[u][0];
        }
        while(v!=x)
        {
            insert(w[v]);
            v=f[v][0];
        }
        insert(x);
        ll ans=0;
        for(int i=60;i>=0;i--)
            if((ans^p[i])>ans)
                ans^=p[i];
        cout<<ans<<endl;
    }
    return 0;
}