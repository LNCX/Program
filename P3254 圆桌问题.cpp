#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5,maxm=1e5+5,inf=0x3f3f3f3f;
struct edge
{
    int nxt,to,f;
}e[maxm];
int head[N],tot=1,dep[N],cur[N];
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
    for(int &i=cur[u];i!=0;i=e[i].nxt)
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
int main()
{
    int m,n;
    scanf("%d%d",&m,&n);
    int s=0,t=n+m+1,sum=0;
    for(int i=1;i<=m;i++)
    {
        int x;
        scanf("%d",&x);
        sum+=x;
        Add(s,i,x);
    }
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        Add(i+m,t,x);
        for(int j=1;j<=m;j++)
            Add(j,i+m,1);
    }
    int flow=dinic(s,t);
    if(flow<sum)
    {
        puts("0");
        return 0;
    }
    puts("1");
    for(int u=1;u<=m;u++)
    {
        for(int i=head[u];i!=0;i=e[i].nxt)
            if(e[i].f==0)
                printf("%d ",e[i].to-m);
        puts("");
    }
    return 0;
}