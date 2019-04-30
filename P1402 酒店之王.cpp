#include<bits/stdc++.h>
using namespace std;
const int maxn=1005,inf=0x3f3f3f3f;
int n,p,q,tot=1,head[maxn],dep[maxn],vis[maxn],cur[maxn];
struct edge
{
    int nxt,to,cap,flow; 
}e[maxn*maxn<<1];
void Add(int u,int v,int cap)
{
    e[++tot]=(edge){head[u],v,cap,0};
    head[u]=tot;
}
bool bfs(int s,int t)
{
    for(int i=0;i<=t;i++)
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
    scanf("%d%d%d",&n,&p,&q);
    int s=2*n+q+p+1,t=s+1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=p;j++)
        {
            int x;
            scanf("%d",&x);
            if(x^1) continue;
            Add(j,p+i,1);
            Add(p+i,j,0);
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=q;j++)
        {
            int x;
            scanf("%d",&x);
            if(x^1) continue;
            Add(p+n+q+i,p+n+j,1);
            Add(p+n+j,p+n+q+i,0);
        }
    for(int i=1;i<=n;i++) Add(p+i,p+n+q+i,1),Add(p+n+q+i,p+i,0);
    for(int i=1;i<=p;i++) Add(s,i,1),Add(i,s,0);
    for(int i=p+1+n;i<=p+n+q;i++) Add(i,t,1),Add(t,i,0);
    cout<<dinic(s,t)<<endl;
    return 0;
}