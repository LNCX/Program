#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5,inf=0x3f3f3f3f;
struct edge
{
    int nxt,to,f;
}e[maxn<<2];
int head[maxn],tot=1;
int dep[maxn],cur[maxn],ans;
void add(int u,int v,int f)
{
    e[++tot]=(edge){head[u],v,f},head[u]=tot;
    e[++tot]=(edge){head[v],u,0},head[v]=tot;
}
bool bfs(int s,int t)
{
    for(int i=s;i<=t;i++)
    {
        dep[i]=inf;
        cur[i]=head[i];
    }
    queue<int>q;
    q.push(s),dep[s]=0;
    while(!q.empty())
    {
        int u=q.front();q.pop();
        for(int i=head[u];i!=0;i=e[i].nxt)
        {
            int v=e[i].to;
            if(dep[v]!=inf||e[i].f<=0) continue;
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
        if(dep[u]+1==dep[v]&&e[i].f>0)
        {
            int f=dfs(v,t,min(add,e[i].f));
            e[i].f-=f,e[i^1].f+=f;
            flow+=f,add-=f;
            if(add==0) break;
        }
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
    int n,m;
    scanf("%d%d",&n,&m);
    int s=0,t=n+m+1;
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        add(s,i,x);
    }
    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        add(a,i+n,inf);
        add(b,i+n,inf);
        add(i+n,t,c);
        ans+=c;
    }
    cout<<ans-dinic(s,t)<<endl;
}