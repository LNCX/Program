#include<bits/stdc++.h>
using namespace std;
const int maxn=505,inf=0x3f3f3f3f;
class net
{
    public:
    int head[maxn],dis[maxn],vis[maxn],cost=0,tot=1;
    struct edge
    {
        int nxt,to,f,w;
    }e[maxn*maxn<<1];
    void add(int u,int v,int f,int w)
    {
        e[++tot]=(edge){head[u],v,f,w},head[u]=tot;
        e[++tot]=(edge){head[v],u,0,-w},head[v]=tot;
    }
    bool SPFA(int s,int t)
    {
        memset(vis,0,sizeof(vis));
        memset(dis,inf,sizeof(dis));
        queue<int>q;
        q.push(s);
        dis[s]=0,vis[s]=1;
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
        if(add==0||u==t)
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
                cost+=f*w;
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
        return cost;
    }
}n1,n2;
int main()
{
    int n;
    cin>>n;
    int s=0,t=2*n+1;
    for(int i=1;i<=n;i++)
    {
        n1.add(s,i,1,0),n2.add(s,i,1,0);
        n1.add(i+n,t,1,0),n2.add(i+n,t,1,0);
        for(int j=1;j<=n;j++)
        {
            int x;
            scanf("%d",&x);
            n1.add(i,j+n,1,x),n2.add(i,j+n,1,-x);
        }
    }
    printf("%d\n",n1.mcmf(s,t));
    printf("%d\n",-n2.mcmf(s,t));
    return 0;
}