#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f,maxn=2e5+5;
struct node
{
    int to,w,nxt;
}e[maxn<<1];
int head[maxn<<1],dep[maxn],tot,dis[maxn];
void add(int u,int v,int w)
{
    e[++tot].to=v;
    e[tot].w=w;
    e[tot].nxt=head[u];
    head[u]=tot;
}
void dfs(int u,int fa)
{
    dep[u]=dep[fa]+1;
    for(int i=head[u];i;i=e[i].nxt)
    {
        int v=e[i].to,w=e[i].w;
        if(v!=fa)
        {
            dis[v]=w;
            if(dep[u]%2==0)
                dis[u]=min(dis[u],dis[v]);
        }
    }
    for(int i=head[u];i;i=e[i].nxt)
    {
        int v=e[i].to;
        if(v!=fa)
        {
            dfs(v,u);
            if(dis[v]!=inf)
                dis[v]=dis[v]-dis[u];
        }
    }
}
int a[maxn],b[maxn];
int main()
{
    int n;
    cin>>n;
    for(int i=2;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
        if(b[i]==-1) b[i]=inf;
    }
    for(int i=2;i<=n;i++)
    {
        add(a[i],i,b[i]);
        add(i,a[i],b[i]);
    }
    dis[1]=b[1];
    dfs(1,0);
    for(int i=1;i<=n;i++)
        if(dis[i]==inf)
            dis[i]=0;
    long long ans=0;
    int flag=0;
    for(int i=1;i<=n;i++)
    {
        if(dis[i]<0)
        {
            flag=1;
            break;
        }
        ans+=dis[i];
    }
    flag==0?printf("%lld\n",ans):puts("-1");
}