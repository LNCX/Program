#include<bits/stdc++.h>
using namespace std;
const long long maxn=8e3+5,maxm=4e5+5,inf=0x3f3f3f3f3f3f3f3f;
long long maxflow,cost,tot=1,head[maxn],vis[maxn],dis[maxn],r[maxn];
struct edge
{
    long long nxt,to,f,w;
}e[maxm];
void add(long long u,long long v,long long f,long long w)
{
    e[++tot]=(edge){head[u],v,f,w},head[u]=tot;
    e[++tot]=(edge){head[v],u,0,-w},head[v]=tot;
}
bool SPFA(long long s,long long t)
{
    for(long long i=0;i<=t;i++)
        vis[i]=0,dis[i]=inf;
    dis[s]=0;vis[s]=1;
    queue<long long>q;
    q.push(s);
    while(!q.empty())
    {
        long long u=q.front();
        q.pop();
        vis[u]=0;
        for(long long i=head[u];i!=0;i=e[i].nxt)
        {
            long long v=e[i].to;
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
long long dfs(long long u,long long t,long long add)
{
    if(u==t||add==0)
    {
        vis[t]=1;
        maxflow+=add;
        return add;
    }
    long long flow=0;
    vis[u]=1;
    for(long long i=head[u];i!=0;i=e[i].nxt)
    {
        long long v=e[i].to,w=e[i].w;
        if((vis[v]==0||v==t)&&e[i].f>0&&dis[v]==dis[u]+w)
        {
            long long f=dfs(v,t,min(add,e[i].f));
            cost+=w*f;
            e[i].f-=f,e[i^1].f+=f;
            flow+=f,add-=f;
            if(add==0) break;
        }
    }
    return flow;
}
long long mcmf(long long s,long long t)
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
signed main()
{
    long long n,p,m,f,m1,f1;
    scanf("%lld",&n);
    long long s=0,t=2*n+1;
    for(long long i=1;i<=n;i++)
        scanf("%lld",&r[i]);
    scanf("%lld%lld%lld%lld%lld",&p,&m,&f,&m1,&f1);
    for(long long i=1;i<=n;i++)
    {
        add(s,i,r[i],0);
        if(i<n) add(i,i+1,inf,0);
        if(i+m<=n) add(i,i+m+n,inf,f);
        if(i+m1<=n) add(i,i+m1+n,inf,f1);
        add(s,i+n,r[i],p);
        add(i+n,t,r[i],0);
    }
    cout<<mcmf(s,t)<<endl;
}