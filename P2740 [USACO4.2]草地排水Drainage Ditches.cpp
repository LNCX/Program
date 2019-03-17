#include<bits/stdc++.h>
using namespace std;
const int maxn=2e2+5,inf=0x3f3f3f3f;
int n,m,tot=1,head[maxn],dep[maxn],vis[maxn],cur[maxn];
struct Edge
{
    int to,cap,nxt,flow,from; 
}e[maxn<<1];
void Add(int from,int to,int cap)
{
    e[++tot].nxt=head[from];
    e[tot].cap=cap;
    e[tot].from=from;
    e[tot].to=to;
    head[from]=tot;
}
bool bfs()
{
    for(int i=0;i<=n;i++)
        cur[i]=head[i],dep[i]=inf,vis[i]=0;
    dep[1]=0;
    queue<int>q;q.push(1);
    while(!q.empty())
    {
        int u=q.front();
        vis[u]=1;q.pop();
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
    return vis[n];
}
int dfs(int u,int add)
{
    if(u==n||add==0) return add;
    int flow=0;     
    for(int &i=cur[u];i!=0;i=e[i].nxt)
    {
        int v=e[i].to;
        if(e[i].cap-e[i].flow<=0||dep[u]+1!=dep[v]) continue;
        int f=dfs(v,min(add,e[i].cap-e[i].flow));
        e[i].flow+=f;
        e[i^1].flow-=f;
        flow+=f;
        add-=f;
        if(add==0) break;
    }
    return flow;
}
int dinic(int s,int t)
{
    int flow=0;
    while(bfs())
        flow+=dfs(s,inf);
    return flow;
}
int main()
{
    scanf("%d%d",&m,&n);
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        Add(x,y,z),Add(y,x,0);
    }
    printf("%d\n",dinic(1,n));
    return 0;
}