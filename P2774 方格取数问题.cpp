#include<bits/stdc++.h>
using namespace std;
const int N=10005,inf=0x3f3f3f3f;
int n,m,s,t,sum;
struct edge
{
    int nxt,to,cap,flow;
}e[N<<3];
bitset<N>vis;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int head[N],cur[N],dep[N],tot=1;
void Add(int u,int v,int w)
{
    e[++tot]=(edge){head[u],v,w,0};
    head[u]=tot;
    e[++tot]=(edge){head[v],u,0,0};
    head[v]=tot;
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
int calc(int x,int y){return ((x-1)*m+y);}
int main()
{
    scanf("%d%d",&n,&m);
    int s=n*m+1,t=s+1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            int x;
            scanf("%d",&x);
            sum+=x;
            if((i+j)&1) 
            {
                Add(s,calc(i,j),x);
                for(int k=0;k<4;k++)
                {
                    int x=i+dx[k],y=j+dy[k];
                    if(x<1||x>n||y<1||y>m) continue;
                    Add(calc(i,j),calc(x,y),inf);
                }
            }
            else Add(calc(i,j),t,x);
        }
    cout<<sum-dinic(s,t)<<endl;
    return 0;
}