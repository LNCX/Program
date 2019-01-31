#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=1505;
const int inf=0x3f3f3f3f;
int n,m,x1,x2,y1,y2,ans;
int Map[maxn][maxn],cost[maxn][maxn];
int head[maxn*maxn],nxt[maxn*maxn],w[maxn*maxn],to[maxn*maxn],edge_sum;
void add(int u,int v,int c)
{
    nxt[++edge_sum]=head[u];
    to[edge_sum]=v;
    w[edge_sum]=c;
    head[u]=edge_sum;
}
int dis[maxn],pre[maxn];
priority_queue<pair<int,int> >q;
void dijkstra(int s)
{
    memset(dis,inf,sizeof dis);
    memset(pre,inf,sizeof pre);
    while(q.size()) q.pop();
    dis[s]=0,pre[s]=0;
    q.push(make_pair(0,s));
    while(q.size()!=0)
    {
        int x=q.top().second;q.pop();
        for(int i=head[x];i!=0;i=nxt[i])
        {
            int y=to[i],z=w[i];
            if(dis[x]+z<dis[y])
            {
                dis[y]=dis[x]+z;
                q.push(make_pair(-dis[y],y));
                pre[y]=x;
            }
        }
    }
}
int main(int argc, char const *argv[])
{
    scanf("%d%d",&n,&m);
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w),add(v,u,w);
        cost[u][v]=cost[v][u]=w;
    }
    dijkstra(x1);
    #ifdef DEBUG
        cout<<dis[y1]<<endl;
        for(int i=y1;i!=0;i=pre[i])
            printf("%d ",i);
        printf("\n");
    #endif
    
    for(int i=y1;i!=0;i=pre[i])
        Map[pre[i]][i]=1;
    dijkstra(x2);
    #ifdef DEBUG
        cout<<dis[y1]<<endl;
        for(int i=y2;i!=0;i=pre[i])
            printf("%d ",i);
        printf("\n");
    #endif

    for(int i=y2;i!=0;i=pre[i])
        if(Map[pre[i]][i]==1)
        {
            #ifdef DEBUG
                printf("%d ",cost[pre[i]][i]);
            #endif
            ans+=cost[pre[i]][i];
        }
        puts("");
    cout<<ans<<endl;
    return 0;
}