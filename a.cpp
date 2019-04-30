#include<bits/stdc++.h>
using namespace std;
const int maxn=5e3+5,maxm=1e5+5,inf=0x3f3f3f3f;
int n,m,s,t,tot=1,maxflow,mincost,head[maxn],vis[maxn],dis[maxn];
struct edge
{
    int nxt,to,f,w;
}e[maxm];
void Add(int u,int v,int f,int w)
{
    e[++tot]=(edge){head[u],v,f,w};
    head[u]=tot;
    e[++tot]=(edge){head[v],u,0,-w};
    head[v]=tot;
}
bool spfa(int s,int t)
{
    memset(vis,0,sizeof(vis));
    memset(dis,inf,sizeof(dis));
    queue<int>q;q.push(s);
    dis[s]=0,vis[s]=1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop(),vis[u]=0;
        for(int i=head[u];i!=0;i=e[i].nxt)
        {
            int v=e[i].to,w=e[i].w,f=e[i].f;
            if(dis[v]>dis[u]+w&&f>0)
            {
                dis[v]=dis[u]+w;
                if(!vis[v])
                {
                    vis[v]=1;
                    q.push(v);
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
        maxflow+=add;
        return add;
    }
    int flow=0;
    vis[u]=1;
    for(int i=head[u];i!=0;i=e[i].nxt)
    {
        int v=e[i].to,w=e[i].w;
        if((!vis[v]||v==t)&&e[i].f>0&&dis[u]+w==dis[v])
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
    while(spfa(s,t))
    {
        vis[t]=1;
        while(vis[t])
        {
            memset(vis,0,sizeof(vis));
            dfs(s,t,inf);
        }
    }
}
int main()
{
    scanf("%d%d%d%d",&n,&m,&s,&t);
    while(m--)
    {
        int u,v,f,w;
        scanf("%d%d%d%d",&u,&v,&f,&w);
        Add(u,v,f,w);
    }
    mcmf(s,t);
    printf("%d %d\n",maxflow,mincost);
    return 0;
}