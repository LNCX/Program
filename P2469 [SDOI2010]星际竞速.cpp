#include<bits/stdc++.h>
using namespace std;
const int maxn=3005,maxm=6e4+5,inf=0x3f3f3f3f;
struct edge
{
    int nxt,to,f,w;
}e[maxm];
int head[maxn],tot=1,vis[maxn],maxflow,mincost,dis[maxn],a[maxn];
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
    dis[s]=0;vis[s]=1;
    queue<int>q;
    q.push(s);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        vis[u]=0;
        for(int i=head[u];i!=0;i=e[i].nxt)
        {
            int v=e[i].to;
            if(dis[v]>dis[u]+e[i].w&&e[i].f>0)
            {
                dis[v]=dis[u]+e[i].w;
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
        maxflow+=add;
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
int mcmf(int s,int t)
{
    while(SPFA(s,t))
    {
        vis[t]=1;
        while(vis[t])
        {
            memset(vis,0,sizeof(vis));
            dfs(s,t,inf);
        }
    }
    return mincost;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int s=1,t=(n<<1)+2;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        if(x>y) swap(x,y);
        if(z<a[y]) Add(x+1,y+n+1,1,z);
    }
    for(int i=1;i<=n;i++)
    {
        Add(s,i+1,1,0);
        Add(i+n+1,t,1,0);
        Add(s,i+n+1,1,a[i]);
    }
    printf("%d\n",mcmf(s,t));
    return 0;
}