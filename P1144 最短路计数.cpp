#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
const int inf=0x3f3f3f3f;
int head[N],to[N<<1],nxt[N<<1],tot;
void add(int u,int v)
{
    nxt[++tot]=head[u];
    to[tot]=v;
    head[u]=tot;
}
int dis[N],ans[N];
priority_queue< pair<int,int> >q;
void dijkstra(int s)
{
    q.push(make_pair(0,s));
    memset(dis,inf,sizeof(dis));
    dis[s]=0;ans[s]=1;
    while(q.size())
    {
        int x=q.top().second;q.pop();
        for(int i=head[x];i!=0;i=nxt[i])
        {
            int y=to[i];
            if(dis[x]+1<dis[y])
            {
                dis[y]=dis[x]+1;
                ans[y]=ans[x];
                q.push(make_pair(-dis[y],y));
            } 
            else if(dis[x]+1==dis[y])
            {
                ans[y]+=ans[x];
                ans[y]%=100003;
            }
        }
    }
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add(x,y),add(y,x);
    }
    dijkstra(1);
    for(int i=1;i<=n;i++)
        printf("%d\n",ans[i]);
    return 0;
}