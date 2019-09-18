#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=4e6+5,inf=0x3f3f3f3f;
int tot=1,head[N],dep[N],cur[N],num;
struct edge
{
    int nxt,to,f;
}e[M];
void add(int u,int v,int f)
{
    e[++tot]=(edge){head[u],v,f},head[u]=tot;
    e[++tot]=(edge){head[v],u,0},head[v]=tot;
}
bool bfs(int s,int t)
{
    for(int i=0;i<=num;i++)
        cur[i]=head[i],dep[i]=inf;
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
        flow+=f,add-=f;
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
    int n,m,sum=0;
    scanf("%d",&n);
    int s=0,t=n+1;
    for(int i=1,x;i<=n;i++) scanf("%d",&x),sum+=x,add(s,i,x);
    for(int i=1,x;i<=n;i++) scanf("%d",&x),sum+=x,add(i,t,x);
    scanf("%d",&m);
    num=n+2*m+1;
    for(int i=1;i<=m;i++)
    {
        int k,x,y;
        scanf("%d%d%d",&k,&x,&y);
        sum+=x+y;
        add(s,n+1+i,x),add(n+m+1+i,t,y);
        while(k--)
        {
            int t;
            scanf("%d",&t);
            add(n+i+1,t,inf),add(t,n+m+i+1,inf);
        }
    }
    cout<<sum-dinic(s,t)<<endl;
    return 0;

}