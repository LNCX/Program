#include<bits/stdc++.h>
using namespace std;
const int N=16e3+5;
vector<int>e[N<<1];
int w[N],f[N],n,ans;
void dfs(int u,int fa)
{
    f[u]=w[u];
    for(auto v:e[u])
    {
        if(v==fa) continue;
        dfs(v,u);
        if(f[v]>0)
            f[u]+=f[v];
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&w[i]);
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++)
        ans=max(ans,f[i]);
    ans<0?puts("0"):printf("%d\n",ans);
    return 0;
}