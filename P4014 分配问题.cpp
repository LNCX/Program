#include<bits/stdc++.h>
using namespace std;
const int maxn=205,inf=0x3f3f3f3f;
int n,tot=1,cost;
int a[maxn][maxn];
int head[maxn],dis[maxn],vis[maxn];
struct edge
{
    int nxt,to,f,w;
}e[maxn*maxn<<1];
void add(int u,int v,int f,int w)
{
    e[++tot]=(edge){head[u],v,f,w},head[u]=tot;
    e[++tot]=(edge){head[v],u,0,-w},head[v]=tot;
}
bool SPFA(int s,int t,int p)
{
    queue<int>q;
    memset(vis,0,sizeof(vis));
    memset(dis,p*inf,sizeof(dis));
    q.push(s);
    dis[s]=0,vis[s]=1;
    while(!q.empty())
    {
        int u=q.front();q.pop();
        for(int i=head[u];i!=0;i=e[i].nxt)
        {
            int v=e[i].to,w=e[i].w;
            if( ((p==1&&dis[v]>dis[u]+w)||(p==-1&&dis[v]<dis[u]+w)) && e[i].f>0 )
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
    return dis[t]!=p*inf;
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
        if((!vis[v]||v==t)&&e[i].f>0&&dis[v]==dis[u]+w)
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
int mcmf(int s,int t,int type)
{
    cost=0;
    while(SPFA(s,t,type))
    {
        while(vis[t])
        {
            memset(vis,0,sizeof(vis));
            cost+=dfs(s,t,inf);
        }
    }
    return cost;
}
int main()
{
    cin>>n;
    int s=0,t=2*n+1;
    for(int i=1;i<=n;i++)
    {
        add(s,i,1,0);
        add(i+n,t,1,0);
        for(int j=1;j<=n;j++)
        {
            int x;
            scanf("%d",&x);
            add(i,j+n,1,x);
        }
    }
    printf("%d\n%d\n",mcmf(s,t,-1),mcmf(s,t,1));
    return 0;
}