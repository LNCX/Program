#include<bits/stdc++.h>
using namespace std;
const int N=5e4+5,inf=0x3f3f3f3f;
struct node
{
    int u,v,a,b;
    bool operator<(const node k) const
    {
        if(a!=k.a) return a<k.a;
        else return b<k.b;
    }
}a[N<<2];
struct edge
{
    int nxt,to,a,b;
}e[N<<2];
queue<int>q;
int n,m,head[N],tot,vis[N],dis[N],ans=inf;
void add(int u,int v,int a,int b)
{
    e[++tot]=(edge){head[u],v,a,b},head[u]=tot;
    e[++tot]=(edge){head[v],u,a,b},head[v]=tot;
}
void spfa(int maxa)
{
    while(!q.empty())
    {
        int u=q.front();
        q.pop(),vis[u]=0;
        for(int i=head[u];i!=0;i=e[i].nxt)
        {
            int v=e[i].to;
            if(max(dis[u],e[i].b)<dis[v])
            {
                dis[v]=max(dis[u],e[i].b);
                if(!vis[v])
                {
                    q.push(v);
                    vis[v]=1;
                }
            }
        }
    }
    ans=min(ans,dis[n]+maxa);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)   
        scanf("%d%d%d%d",&a[i].u,&a[i].v,&a[i].a,&a[i].b);
    sort(a+1,a+1+m);
    memset(dis,inf,sizeof(dis));
    dis[1]=0;
    int p=1;
    while(p<=m)
    {
        int i=p;
        while(a[p].a==a[i].a)
        {
            add(a[i].u,a[i].v,a[i].a,a[i].b);
            q.push(a[i].u),q.push(a[i].v);
            vis[a[i].u]=vis[a[i].v]=1;
            i++;
        }
        spfa(a[p].a);
        p=i;
    }
    ans==inf?puts("-1"):printf("%d\n",ans);
    return 0;
}