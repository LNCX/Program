#include<bits/stdc++.h>
using namespace std;
const int N=3e3+5,inf=0x3f3f3f3f;
int a[N],b[N],c[N];
int tot=1,head[N],cur[N],dep[N];
struct edge
{
    int nxt,to,f;
}e[N*N<<1];
void add(int u,int v,int f)
{
    e[++tot]=(edge){head[u],v,f},head[u]=tot;
    e[++tot]=(edge){head[v],u,0},head[v]=tot;
}
bool bfs(int s,int t)
{
    memset(dep,inf,sizeof(dep));
    for(int i=s;i<=t;i++)
        cur[i]=head[i];
    queue<int>q;
    q.push(s),dep[s]=0;
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
    if(add==0||u==t) return add;
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
    int n,m;
    scanf("%d%d",&n,&m);
    int s=0,t=n+m+1;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&a[i],&b[i]);
        add(s,i,1);
    }
    for(int i=1;i<=m;i++)
    {
        int x;
        scanf("%d%d",&c[i],&x);
        add(i+n,t,x);
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i]<=c[j]&&c[j]<=b[i])
                add(i,j+n,1);
    cout<<dinic(s,t)<<endl;
    return 0;
    
}