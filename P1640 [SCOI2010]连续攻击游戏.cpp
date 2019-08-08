#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int head[N],tot,f[N];
bitset<N>vis;
struct edge
{
    int nxt,to;
}e[N<<1];
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
    int n,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,i),add(v,i);
    }
    for(int i=1;i<=1e4;i++)
    {
        vis.reset();
        if(dfs(i)) ans++;
        else break;
    }
    cout<<ans<<endl;
    return 0;
}