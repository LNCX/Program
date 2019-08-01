#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,M=805,inf=0x3f3f3f3f;
struct edge
{
    int nxt,to,w;
}e[N<<1];
struct node
{
    int u,v,w;
    bool operator<(const node k) const
    {
        return w<k.w;
    }
}a[N];
bitset<N>vis;
map<int,int>ma;
int head[N],tot,cnt,dis[M][M];
void add(int u,int v,int w)
{
    e[++tot]=(edge){head[u],v,w},head[u]=tot;
    e[++tot]=(edge){head[v],u,w},head[v]=tot;
}
void spfa(int s)
{
    dis[s][s]=0;
    queue<int>q;
    q.push(s),vis[s]=1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop(),vis[s]=0;
        for(int i=head[u];i!=0;i=e[i].nxt)
        {
            int v=e[i].to,w=e[i].w;
            if(dis[s][v]>dis[s][u]+w)
            {
                dis[s][v]=dis[s][u]+w;
                if(!vis[v])
                {
                    q.push(v);
                    vis[v]=1;
                }
            }
        }
    }
}
int main()
{
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=m;i++)
        scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
    sort(a+1,a+1+m);
    for(int i=1;i<=min(m,k);i++)
    {
        if(!ma.count(a[i].u)) ma[a[i].u]=++cnt;
        if(!ma.count(a[i].v)) ma[a[i].v]=++cnt;
        add(ma[a[i].u],ma[a[i].v],a[i].w);
    }
    memset(dis,inf,sizeof(dis));
    for(int i=1;i<=cnt;i++)
    {
        vis.reset();
        spfa(i);
    }
    vector<int>v;
    for(int i=1;i<=cnt;i++)
        for(int j=i+1;j<=cnt;j++)
            v.push_back(dis[i][j]);
    sort(v.begin(),v.end());
    printf("%d\n",v[k-1]);
    return 0;
}