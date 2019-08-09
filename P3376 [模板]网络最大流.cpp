#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,maxm=4e5+5,inf=0x3f3f3f3f;
struct edge
{
    int nxt,to,f;
}e[maxm];
int n,m;
int head[N],cur[N],dep[N],tot=1;
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
    for(int i=0;i<=n;i++)//or t
        cur[i]=head[i];
    queue<int>q;
    dep[s]=0,q.push(s);
    while(!q.empty())
    {
        int u=q.front();q.pop();
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
    if(u==t||add==0) return add;
    int flow=0;
    for(int &i=cur[u];i!=0;i=e[i].nxt)
    {
        int v=e[i].to,res=e[i].f;
        if(dep[v]!=dep[u]+1||res<=0) continue;
        int f=dfs(v,t,min(add,res));
        add-=f,flow+=f;
        e[i].f-=f,e[i^1].f+=f;
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
    int s,t;
    scanf("%d%d%d%d",&n,&m,&s,&t);
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        Add(x,y,z);
    }
    cout<<dinic(s,t)<<endl;
    return 0;
}