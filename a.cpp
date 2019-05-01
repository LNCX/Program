#include<bits/stdc++.h>
using namespace std;
const int maxn=3e3+5,inf=0x3f3f3f3f;
int n,k,a[55][55],mincost;
int last[maxn],pre[maxn];
int head[maxn],tot=1,vis[maxn],dis[maxn],flow[maxn];
struct edge
{
    int nxt,to,f,w;
}e[maxn<<4];
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
    memset(flow,inf,sizeof(flow));
    queue<int>q;
    q.push(s);
    dis[s]=0,vis[s]=1,pre[t]=-1;
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
                flow[v]=min(e[i].f,flow[u]);
                last[v]=i,pre[v]=u;
                if(!vis[v])
                {
                    q.push(v);
                    vis[v]=1;
                }
            }
        }
    }
    return pre[t]!=-1;
}
void mcmf(int s,int t)
{
    while(SPFA(s,t))
    {
        int u=t;
        mincost+=flow[t]*dis[t];
        while(u!=s)
        {
            e[last[u]].f-=flow[t];
            e[last[u]^1].f+=flow[t];
            u=pre[u];
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