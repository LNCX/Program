#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,inf=0x3f3f3f3f;
int n,k,mincost;
int head[N],tot=1,vis[N],dis[N];
struct edge
{
    int nxt,to,f,w;
}e[N<<1];
void Add(int u,int v,int f,int w)
{
    e[++tot]=(edge){head[u],v,f,w};
    head[u]=tot;
    e[++tot]=(edge){head[v],u,0,-w};
    head[v]=tot;
}
bool SPFA(int s,int t)
{
    memset(vis,0,sizeof(vis));
    memset(dis,inf,sizeof(dis));
    dis[s]=0,vis[s]=1;
    queue<int>q;
    q.push(s);
    while(!q.empty())
    {
        int u=q.front();
        q.pop(),vis[u]=0;
        for(int i=head[u];i!=0;i=e[i].nxt)
        {
            int v=e[i].to,w=e[i].w;
            if(dis[v]>dis[u]+w&&e[i].f>0)
            {
                dis[v]=dis[u]+w;
                if(!vis[v])
                {
                    q.push(v);
                    vis[v]=1;
                }
            }
        }
    }
    return dis[t]!=inf;
}
int dfs(int u,int t,int add)
{
    if(u==t||add==0)
    {
        vis[t]=1;
        return add;
    }
    int flow=0;
    vis[u]=1;
    for(int i=head[u];i!=0;i=e[i].nxt)
    {
        int v=e[i].to,w=e[i].w;
        if((vis[v]==0||v==t)&&e[i].f>0&&dis[v]==dis[u]+w)
        {
            int f=dfs(v,t,min(add,e[i].f));
            mincost+=e[i].w*f;
            e[i].f-=f,e[i^1].f+=f;
            flow+=f,add-=f;
            if(add==0) break;
        }
    }
    return flow;
}
void mcmf(int s,int t)
{
    while(SPFA(s,t))
    {
        vis[t]=1;
        while(vis[t])
        {
            memset(vis,0,sizeof(vis));
            int x=dfs(s,t,inf);
            if(x==0) break;
        }
    }
}
inline int id(int x,int y){return (x-1)*n+y;}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            int x;scanf("%d",&x);
            Add(id(i,j),id(i,j)+n*n,1,-x);
            Add(id(i,j),id(i,j)+n*n,k-1,0);
            if(i<n) Add(id(i,j)+n*n,id(i+1,j),k,0);
            if(j<n) Add(id(i,j)+n*n,id(i,j+1),k,0);
        }
    mcmf(1,2*n*n);
    cout<<-mincost<<endl;
    return 0;
}