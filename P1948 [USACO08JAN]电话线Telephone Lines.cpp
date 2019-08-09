#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5,maxm=2e4+5,oo=0x3f3f3f3f;
int n,m,k;
int head[N],tot;
struct edge
{
    int nxt,to,w;
}e[maxm];
void add(int u,int v,int w)
{
    e[++tot]=(edge){head[u],v,w};
    head[u]=tot;
}
queue<int>q,em;
int dis[N],vis[N];
bool SPFA(int s,int t,int mid)
{
    memset(dis,oo,sizeof(dis));
    q=em;
    q.push(s),dis[s]=0,vis[s]=1;
    while(!q.empty())
    {
        int u=q.front();q.pop(),vis[u]=0;
        for(int i=head[u];i!=0;i=e[i].nxt)
        {
            int v=e[i].to,w=e[i].w;
            if(dis[u]+(int)(w>mid)<dis[v])
            {
                dis[v]=dis[u]+(int)(w>mid);
                if(!vis[v]) q.push(v),vis[v]=1;
            }
        }
    }
    if(dis[t]<=k) return true;
    else return false;
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w),add(v,u,w);
    }
    int l=1,r=1e6,ans=-1;
    while(l<r)
    {
        int mid=(l+r)>>1;
        if(!SPFA(1,n,mid)) l=mid+1;
        else r=mid,ans=mid;
    }
    printf("%d\n",ans);
    return 0;
}