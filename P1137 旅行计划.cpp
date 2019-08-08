#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,tot;
int head[N],in[N],ans[N],vis[N];
struct edge
{
    int nxt,to;
}e[N<<1];
void add(int u,int v)
{   
    e[++tot]=(edge){head[u],v};
    head[u]=tot;
}
void dfs(int u)
{
    vis[u]=1;
    for(int i=head[u];i!=0;i=e[i].nxt)
    {
        int v=e[i].to;
        if(!vis[v]) dfs(v);
        ans[u]=max(ans[v],ans[u]);
    }
    ans[u]++;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        add(v,u),in[u]++;
    }
    for(int i=1;i<=n;i++)
        if(in[i]==0)
            dfs(i);
    for(int i=1;i<=n;i++)
        printf("%d\n",ans[i]);
    return 0;
}