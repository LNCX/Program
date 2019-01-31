#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+5,maxm=1e5+5,inf=0x3f3f3f3f;
int n,m,k,s,t,ans=inf;
int head[maxn],nxt[maxm],to[maxm],w[maxm],tot;
void add(int u,int v,int z)
{
    nxt[++tot]=head[u];
    head[u]=tot;
    to[tot]=v;
    w[tot]=z;
}
struct node
{
    int u,d,used;
    bool operator<(const node&x) const
    {
        return this->d>x.d;
    }
};
int dis[maxn][15],vis[maxn][15];
void dijkstra()
{
    memset(dis,inf,sizeof dis);
    dis[s][0]=0;
    priority_queue<node>q;
    q.push((node){s,0,0});
    while(!q.empty())
    {
        int x=q.top().u,now=q.top().used;
        q.pop();
        if(vis[x][now])continue;
        vis[x][now]=true;
        for(int i=head[x];i!=0;i=nxt[i])
        {
            int y=to[i],z=w[i];
            if(now<k&&!vis[y][now+1]&&dis[y][now+1]>dis[x][now])
            {
                dis[y][now+1]=dis[x][now];
                q.push((node){y,dis[y][now+1],now+1});
            }
            if(!vis[y][now]&&dis[y][now]>dis[x][now]+z)
            {
                dis[y][now]=dis[x][now]+z;
                q.push((node){y,dis[y][now],now});
            }
        }
    }
}
int main()
{
    scanf("%d%d%d%d%d",&n,&m,&k,&s,&t);
    s++,t++;
    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        add(a+1,b+1,c),add(b+1,a+1,c);
    }
    dijkstra();
    for(int i=0;i<=k;i++)
        ans=min(ans,dis[t][i]);
    cout<<ans<<endl;
    return 0;
}