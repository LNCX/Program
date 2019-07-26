#include<bits/stdc++.h>
using namespace std;
const int N=200;
bitset<N>vis;
vector<int>e[N];
int loc[N],out[N],n,T,ans,f[N];
bool dfs(int u)
{
    for(auto v:e[u])
    {
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
void link(int u,int v){e[u].push_back(v+n);}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        cin>>n;
        ans=n;
        memset(f,0,sizeof(f));
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&loc[i]);
            e[i].clear();
        }
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&out[i]);
            if(loc[i])
            {
                if(out[i]) ans--;
                if(!out[i]) link(i,i);
            }
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                int x;
                scanf("%d",&x);
                if(x&&loc[j])
                    link(i,j);
            }
        for(int u=1;u<=n;u++)
            if((loc[u]&&!out[u])||!loc[u])
            {
                vis.reset();
                ans-=dfs(u);
            }
        ans==0?puts("^_^"):puts("T_T");
    }
}