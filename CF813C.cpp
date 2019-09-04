#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
vector<int>e[N];
int f[N],dis[N],dep[N];
void dfs(int u,int fa)
{
    dis[u]=dis[fa]+1;
    dep[u]=dep[fa]+1;
    for(auto v:e[u])
    {
        if(v==fa) continue;
        dfs(v,u);
        
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].push_back(v),e[v].push_back(u);
    }
    dfs(1,0);
    return 0;
}