#include<bits/stdc++.h>
using namespace std;
const int N=6e3+5;
struct edge 
{
    int nxt,to;
}e[N<<1];
int head[N],tot,w[N],f[N][2],in[N];
void add(int u,int v)
{
    e[++tot]=(edge){head[u],v},head[u]=tot;
    e[++tot]=(edge){head[v],u},head[v]=tot;
}
void dfs(int u,int fa)
{
    f[u][1]=w[u];
    for(int i=head[u];i!=0;i=e[i].nxt)
    {
        int v=e[i].to;
        if(v==fa) continue;
        dfs(v,u);
        f[u][0]+=max(f[v][1],f[v][0]);
        f[u][1]+=f[v][0];
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        scanf("%d",&w[i]);
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v);
    }
    dfs(1,0);
    cout<<max(f[1][0],f[1][1])<<endl;
    return 0;
}