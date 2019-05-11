#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
struct edge
{
    int nxt,to;
}e[maxn*maxn<<1];
bitset<maxn<<2>vis;
int head[maxn],f[maxn],tot;
void add(int u,int v)
{
    e[++tot]=(edge){head[u],v};
    head[u]=tot;
    e[++tot]=(edge){head[v],u};
    head[v]=tot;
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
    int v,n1,n2,m;
    scanf("%d%d%d%d",&v,&n1,&n2,&m);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v+n1);
    }
    int ans=0;
    for(int i=1;i<=n1;i++)
    {
        vis.reset();
        ans+=dfs(i);
    }
    cout<<min(v+1,n1+n2-ans)<<endl;
    return 0;
}