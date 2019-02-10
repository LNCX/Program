#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cstdio>
using namespace std;
const int inf=1<<30;
int top=1,head[5010];
int n,m,s,t;
int cost,maxflow;
int vis[5010];//是否到达过该点 
int dist[5010];//到t的单位费用 
struct Node
{
    int val;
    int v;
    int next;
    int w;
}node[101010];
inline int Read()
{
    int x=0;
    char c=getchar();
    while(c>'9'||c<'0')c=getchar();
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    return x;
}
inline void addedge(int u,int v,int val,int w)
{
    node[++top].v=v;
    node[top].w=w;
    node[top].val=val;
    node[top].next=head[u];
    head[u]=top;
}
bool spfa()
{
    memset(vis,0,sizeof(vis));
    memset(dist,0x3f,sizeof(dist));
    dist[s]=0;
    vis[s]=1;
    queue<int>q;
    q.push(s);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        vis[u]=0;
        for(int i=head[u];i;i=node[i].next)
        {
            int d=node[i].v;
            if(dist[d]>dist[u]+node[i].w&&node[i].val)
            {
                dist[d]=dist[u]+node[i].w;
                if(vis[d]==0)
                {
                    q.push(d);
                    vis[d]=1;
                }
            }
        }
    }
    return dist[t]!=0x3f3f3f3f;
}//spfa同EK
inline int min(int x,int y)
{
    return x<y?x:y;
}
int dfs(int u,int flow)
{
    if(u==t)
    {vis[t]=1;maxflow+=flow;return flow;}//可以到达t，加流 
    int used=0;//该条路径可用流量 
    vis[u]=1;
    for(int i=head[u];i;i=node[i].next)
    {
        int d=node[i].v;
        if((vis[d]==0||d==t)&&node[i].val!=0&&dist[d]==dist[u]+node[i].w)
        {
            int minflow=dfs(d,min(flow-used,node[i].val));
            if(minflow!=0)cost+=node[i].w*minflow,node[i].val-=minflow,node[i^1].val+=minflow,used+=minflow;
            //可以到达t，加费用，扣流量 
            if(used==flow)break;
        }
    }
    return used;
}
int mincostmaxflow()
{
    while(spfa())
    {
        vis[t]=1;
        while(vis[t])
        {
        memset(vis,0,sizeof(vis));
        dfs(s,inf); 
        }
    }
    return maxflow;
}
int main()
{
    n=Read(),m=Read(),s=Read(),t=Read();
    int u,v,w,val;
    register int i;
    for(i=1;i<=m;i++)
    {
        u=Read(),v=Read(),val=Read(),w=Read();
        addedge(u,v,val,w);
        addedge(v,u,0,-w);
    }
    mincostmaxflow();
    printf("%d %d",maxflow,cost);
    return 0;
}