#include <bits/stdc++.h>
using namespace std;
const int maxn=2e3+6;
int n,m,t,f[maxn],ans;
bitset<maxn>vis;
struct edge
{
    int nxt,to;
}e[maxn*maxn<<1];
int head[maxn],tot;
void add(int u,int v)
{
    e[++tot]=(edge){head[u],v};
    head[u]=tot;
}
bool dfs(int u)
{
    for(int i=head[u];i!=0;i=e[i].nxt)
    {
        int v=e[i].to;
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
    scanf("%d%d%d",&n,&m,&t);
    while(t--)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        if(u>n||v>m) continue;
        add(u,v+n),add(v+n,u);
    }
    for(int i=1;i<=n;i++)
    {
        vis.reset();
        ans+=dfs(i);
    }
    cout<<ans<<endl;
    return 0;
}