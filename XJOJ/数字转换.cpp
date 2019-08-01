#include<bits/stdc++.h>
using namespace std;
const int N=5e4+5;
int head[N],tot,ans,dis[N];
struct edge
{
    int nxt,to;
}e[N<<1];
void add(int u,int v)
{
    e[++tot]=(edge){head[u],v},head[u]=tot;
    e[++tot]=(edge){head[v],u},head[v]=tot;
}
void link(int u)
{
    int v=0,n=u;
    for(int i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            v+=i;
            if(i*i!=n&&i!=1)
                v+=n/i;
        }
    }
    if(v<u)
    {
        add(u,v);
    }
}
int dfs(int u,int fa)
{
    int maxx=u;
    for(int i=head[u];i!=0;i=e[i].nxt)
    {
        int v=e[i].to;
        if(v==fa) continue;
        dis[v]=dis[u]+1;
        int x=dfs(v,u);
        if(dis[maxx]<dis[x]) maxx=x;
    }
    return maxx;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        link(i);
    int x=dfs(1,0);dis[x]=0;
    int y=dfs(x,0);
    printf("%d\n",dis[y]);
    return 0;
}