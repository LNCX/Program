#include<bits/stdc++.h>
using namespace std;
const int maxn=5e3+5,maxm=1e5+5,inf=0x3f3f3f3f;
int n,m,s,t,tot=1,head[maxn],vis[maxn],dis[maxn];
struct Edge
{
    int to,cap,nxt,w,flow;
}e[maxm];
void Add(int from,int to,int cap,int w)
{
    e[++tot].nxt=head[from];
    e[tot].to=to;
    e[tot].cap=cap;
    e[tot].w=w;
    head[from]=tot;
}
bool SPFA()
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
            if(dis[v]>dis[u]+e[i].w&&e[i].cap-e[i].flow>0)
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
void mcmf()
{
    while()
}
int main()
{
    scanf("%d%d%d%d",&n,&m,&s,&t);
    for(int i=1;i<=m;i++)
    {
        int u,v,w,f;
        scanf("%d%d%d%d",&u,&v,&w,&f);
        Add(u,v,w,f);Add(v,u,0,-f);
    }
    mcmf();
    return 0;
}