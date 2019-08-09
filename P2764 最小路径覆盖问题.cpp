#include<bits/stdc++.h>
using namespace std;
const int N=505,maxm=2e4+5,inf=0x3f3f3f3f;
struct edge
{
    int nxt,to,f;
}e[maxm<<1];
int head[N],dep[N],cur[N],tot=1;
void Add(int u,int v,int w)
{
    e[++tot]=(edge){head[u],v,w};
    head[u]=tot;
    e[++tot]=(edge){head[v],u,0};
    head[v]=tot;
}
bool bfs(int s,int t)
{   
    memset(dep,inf,sizeof(dep));
    for(int i=0;i<=t;i++)
        cur[i]=head[i];
    queue<int>q;
    q.push(s),dep[s]=0;
    while(!q.empty())
    {
        int u=q.front();q.pop();
        for(int i=head[u];i!=0;i=e[i].nxt)
        {
            int v=e[i].to,f=e[i].f;
            if(dep[v]==inf&&f>0)
            {
                dep[v]=dep[u]+1;
                q.push(v);
            }
        }
    }
    return dep[t]!=inf;
}
int dfs(int u,int t,int add)
{
    if(add==0||u==t) return add;
    int flow=0;
    for(int i=cur[u];i!=0;i=e[i].nxt)
    {
        int v=e[i].to,res=e[i].f;
        if(res<=0||dep[v]!=dep[u]+1) continue;
        int f=dfs(v,t,min(add,res));
        e[i].f-=f,e[i^1].f+=f;
        add-=f,flow+=f;
    }
    return flow;
}
int dinic(int s,int t)
{
    int flow=0;
    while(bfs(s,t))
        flow+=dfs(s,t,inf);
    return flow;
}
int n,m,vis[N];
void dfs(int u)
{
    if(vis[u]) return;
    printf("%d ",u);
    vis[u]=1;
    for(int i=head[u];i!=0;i=e[i].nxt)
    {
        int v=e[i].to,f=e[i].f;
        if(vis[v]||f>0||v==0) continue;
        dfs(v-n);
    }
} 
int main()
{
    scanf("%d%d",&n,&m);
    while(m--)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        Add(u,v+n,1);
    }
    int s=0,t=2*n+1;
    for(int i=1;i<=n;i++) 
        Add(s,i,1),Add(i+n,t,1);
    int flow=dinic(s,t);
    for(int i=1;i<=n;i++)
        if(!vis[i])
        {
            dfs(i);
            puts("");
        }
    printf("%d\n",n-flow);
    return 0;
}