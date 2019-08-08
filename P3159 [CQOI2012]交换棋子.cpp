#include<bits/stdc++.h>
#define left(i,j) ((i-1)*m+j)
#define now(i,j) (((i-1)*m+j)+n*m)
#define right(i,j) (((i-1)*m+j)+(n*m<<1))
using namespace std;
const int N=2e3+5,inf=0x3f3f3f3f;
const int dx[]={-1,-1,-1,0,0,1,1,1},dy[]={-1,0,1,-1,1,-1,0,1};
int n,m,cost,tot=1,head[N],vis[N],dis[N],x1[25][25],x2[25][25];
struct edge
{
    int nxt,to,f,w;
}e[N<<3];
void add(int u,int v,int w,int f)
{
    e[++tot]=(edge){head[u],v,f,w},head[u]=tot;
    e[++tot]=(edge){head[v],u,0,-w},head[v]=tot;
}
bool SPFA(int s,int t)
{
    memset(vis,0,sizeof(vis));
    memset(dis,inf,sizeof(dis));
    dis[s]=0;vis[s]=1;
    queue<int>q;
    q.push(s);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        vis[u]=0;
        for(int i=head[u];i!=0;i=e[i].nxt)
        {
            int v=e[i].to;
            if(dis[v]>dis[u]+e[i].w&&e[i].f>0)
            {
                dis[v]=dis[u]+e[i].w;
                if(!vis[v])
                {
                    q.push(v);
                    vis[v]=1;
                }
            }
        }
    }
    return dis[t]!=inf;
}
int dfs(int u,int t,int add)
{
    if(u==t||add==0)
    {
        vis[t]=1;
        return add;
    }
    int flow=0;
    vis[u]=1;
    for(int i=head[u];i!=0;i=e[i].nxt)
    {
        int v=e[i].to,w=e[i].w;
        if((vis[v]==0||v==t)&&e[i].f>0&&dis[v]==dis[u]+w)
        {
            int f=dfs(v,t,min(add,e[i].f));
            cost+=w*f;
            e[i].f-=f,e[i^1].f+=f;
            flow+=f,add-=f;
            if(add==0) break;
        }
    }
    return flow;
}
int mcmf(int s,int t)
{
    int flow=0;
    while(SPFA(s,t))
    {
        vis[t]=1;
        while(vis[t])
        {
            memset(vis,0,sizeof(vis));
            flow+=dfs(s,t,inf);
        }
    }
    return flow;
}
int main()
{
    char c[30];
    int n,m,t1=0,t2=0;
    scanf("%d%d",&n,&m);
    int s=0,t=3*n*m+1;
    for(int i=1;i<=n;i++)
    {
        scanf("%s",c);
        for(int j=1;j<=m;j++)
            if(c[j-1]=='1')
            {
                t1++;add(s,now(i,j),0,1);
                x1[i][j]=1;
            }
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%s",c);
        for(int j=1;j<=m;j++)
            if(c[j-1]=='1')
            {
                t2++;add(now(i,j),t,0,1);
                x2[i][j]=1;
            }
    }
    if(t1!=t2)
        return puts("-1"),0;
    for(int i=1;i<=n;i++)
    {
        scanf("%s",c);
        for(int j=1;j<=m;j++)
        {
            t2=c[j-1]-'0';
            if(x1[i][j]==x2[i][j]) 
                add(left(i,j),now(i,j),0,t2/2),add(now(i,j),right(i,j),0,t2/2);
            if(x1[i][j]&&!x2[i][j])
                add(left(i,j),now(i,j),0,t2/2),add(now(i,j),right(i,j),0,(t2+1)/2);
            if(!x1[i][j]&&x2[i][j])
                add(left(i,j),now(i,j),0,(t2+1)/2),add(now(i,j),right(i,j),0,t2/2);
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            for(int k=0;k<8;k++)
            {
                int ti=i+dx[k],tj=j+dy[k];
                if(ti<1||ti>n||tj<1||tj>m) continue;
                add(right(i,j),left(ti,tj),1,inf);
            }
    if(mcmf(s,t)!=t1)
        return puts("-1"),0;
    cout<<cost<<endl;
}