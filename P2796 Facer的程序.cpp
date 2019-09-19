#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5,mod=1000000007;
vector<int>e[N];
int f[N];
void dfs(int u,int fa)
{
    f[u]=1;
    for(auto v:e[u])
    {
        if(v==fa) continue;
        dfs(v,u);
        (f[u]*=(f[v]+1))%=mod;
    }
}
signed main()
{
    int n;
    scanf("%lld",&n);
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%lld%lld",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1,0);
    int ans=0;
    for(int i=1;i<=n;i++)
        (ans+=f[i])%=mod;
    printf("%lld\n",ans);
    return 0;
}