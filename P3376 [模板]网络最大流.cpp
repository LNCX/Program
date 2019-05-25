#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+5,maxm=4e5+5,inf=0x3f3f3f3f;
struct edge
{
    int nxt,to,cap,flow;
}e[maxm];
int n,m;
int head[maxn],cur[maxn],dep[maxn],tot=1,vis[maxn];
void Add(int u,int v,int w)
{
    e[++tot]=(edge){head[u],v,w,0};
    head[u]=tot;
    e[++tot]=(edge){head[v],u,0,0};
    head[v]=tot;
}
bool bfs(int s,int t)
{
    for(int i=0;i<=n;i++)
        cur[i]=head[i],dep[i]=inf,vis[i]=0;
    dep[s]=0,vis[s]=1;
    queue<int>q;q.push(s);
    while(!q.empty())
    {
        int u=q.front();q.pop();
        for(int i=head[u];i!=0;i=e[i].nxt)
        {
            int v=e[i].to;
            if(!vis[v]&&e[i].cap-e[i].flow>0)
            {
                vis[v]=1;
                dep[v]=dep[u]+1;
                q.push(v);
            }
        }
    }
    return vis[t];
}
int dfs(int u,int t,int add)
{
    if(u==t||add==0) return add;
    int flow=0;     
    for(int &i=cur[u];i!=0;i=e[i].nxt)
    {
        int v=e[i].to;
        if(e[i].cap-e[i].flow<=0||dep[u]+1!=dep[v]) continue;
        int f=dfs(v,t,min(add,e[i].cap-e[i].flow));
        e[i].flow+=f;
        e[i^1].flow-=f;
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