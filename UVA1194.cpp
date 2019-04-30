#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
bitset<maxn>vis;
vector<int>e[maxn];
int n,m,k,ans,f[maxn];
bool dfs(int u)
{
    for(int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i];
        if(vis[v]) continue;
        vis[v]=1;
        if(!f[v]||dfs(f[v]))
        {
            f[v]=u;
            return true;
        }
    }
    return false;
}
int main()
{
    while(scanf("%d",&n)&&n!=0)
    {
        for(int i=1;i<=n;i++)
            e[i].clear();
        memset(f,0,sizeof f);
        scanf("%d%d",&m,&k);
        for(int i=0;i<k;i++)
        {
            int x,y;
            scanf("%d%d%d",&i,&x,&y);
            e[x].push_back(y);
        }
        ans=0;
        for(int i=1;i<=n;i++)
        {
            vis.reset();
            ans+=dfs(i);
        }
        printf("%d\n",ans);
    }
}