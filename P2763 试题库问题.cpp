#include<bits/stdc++.h>
using namespace std;
const int N=1e4+4,inf=0x3f3f3f3f;
struct edge
{
    int nxt,to,f;
}e[N<<1];
int head[N],tot=1,dep[N],cur[N];
void Add(int u,int v,int f)
{
    e[++tot]=(edge){head[u],v,f};
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
        int u=q.front();
        for(int i=head[u];i!=0;i=e[i].nxt)
        {
            int v=e[i].to,f=e[i].f;
            if(dep[v]!=inf||f<=0) continue;
            dep[v]=dep[u]+1;
            q.push(v);
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
        int v=e[i].to;
        if(e[i].f<=0||dep[v]!=dep[u]+1) continue;
        int f=dfs(v,t,min(f,add));
        e[i].f-=f,e[i^1].f=f;
        flow+=f,add-=f;
        if(add==0) break;
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
    int n,k,m=0;
    scanf("%d%d",&n,&k);
    int s=0,t=n+k+1;
    for(int i=1;i<=k;i++)
    {
        int x;
        scanf("%d",&x);
        Add(i+n,t,x);
        m+=x;
    }
    for(int i=1;i<=n;i++)
    {
        int op,x;
        scanf("%d",&op);
        Add(s,i,1);
        for(int j=1;j<=op;j++)
        {
            scanf("%d",&x);
            Add(i,j+n,1);
        }
    }
    int flow=dinic(s,t);
    cout<<flow<<endl;
    return 0;
}