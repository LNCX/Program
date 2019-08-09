#include<bits/stdc++.h>
using namespace std;
const int N=205,inf=0x3f3f3f3f;
int n,m,a[N][N],tot=1;
int head[N*N],cur[N*N],dep[N*N],vis[N*N];
int dx[]={2,2,1,1,-1,-1,-2,-2},
    dy[]={1,-1,2,-2,2,-2,1,-1};
struct edge
{
    int nxt,to,cap,flow;
}e[N*N<<4];
void edge_add(int u,int v,int w)
{
    e[++tot]=(edge){head[u],v,w,0};
    head[u]=tot;
    e[++tot]=(edge){head[v],u,0,0};
    head[v]=tot;
}
void init()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        a[x][y]=1;
    }
}
int calc(int x,int y){return (x-1)*n+y;}
void build()
{
    int s=n*n+1,t=s+1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            if(a[i][j]) continue;
            if(i+j&1)//黑白染色
                for(int k=0;k<8;k++)
                {
                    int x=i+dx[k],y=j+dy[k];
                    if(x<1||x>n||y<1||y>n||a[i][j])
                        continue;
                    edge_add(calc(i,j),calc(x,y),1);
                }
            if(i+j&1) edge_add(s,calc(i,j),1);
            else  edge_add(calc(i,j),t,1);
        }
}
bool bfs(int s,int t)
{
    for(int i=0;i<=t;i++)
        cur[i]=head[i],dep[i]=inf,vis[i]=0;
    dep[s]=0;
    queue<int>q;q.push(s);
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
    init();
    build();
    cout<<n*n-m-dinic(n*n+1,n*n+2)<<endl;
    return 0;
}