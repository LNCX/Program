#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
vector<int>e[N];
int n,m,rt,vis[N],t[N],w[N],s[N],ans,mx;
void dfs(int u,int fa) 
{
    vis[u]=1;
    for(auto v:e[u])
    {
        if(v==fa) continue;
        if(vis[v]) t[u]=1;
        else dfs(v,u),t[u]|=t[v];
    }
    if(!t[u])
    {
        for(auto v:e[u])
        {
            if(v==fa) continue;
            s[u]=max(s[u],s[v]);
        }
        s[u]+=w[u];
    }
}
signed main()
{
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lld",&w[i]);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%lld%lld",&u,&v);
        e[u].push_back(v),e[v].push_back(u);
    }
    scanf("%lld",&rt);
    dfs(rt,0);
    for(int i=1;i<=n;i++)
    {
        if(t[i]) ans+=w[i];
        if(mx<s[i]) mx=s[i];
    }
    printf("%lld\n",ans+mx);
    return 0;
}