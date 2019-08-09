#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct Edge
{
    int nxt,v,w;
}e[N<<1];
long long dis[N]; 
int n,tot,head[N],a[N],ans[N],f[N][20];
void Add(int u,int v,int w)
{
    e[++tot]=(Edge){head[u],v,w};
    head[u]=tot;
}
void dfs(int u,int fa,int len)
{
    f[u][0]=fa;
    dis[u]=dis[fa]+len;
    for(int i=1;i<=18;i++)
        f[u][i]=f[f[u][i-1]][i-1];
    for(int i=head[u];i;i=e[i].nxt)
    {
        int v=e[i].v,w=e[i].w;
        dfs(v,u,w);
        int now=v,size=a[v];
        for(int i=18;i>=0;i--)
        if(f[now][i]!=0&&dis[now]-dis[f[now][i]]<=size)
            now=f[now][i],size-=dis[now]-dis[f[now][i]];
        ans[f[now][0]]--;
        ans[f[v][0]]++;
    }
    ans[fa]+=ans[u];
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=2;i<=n;i++)
    {
        int u,w;
        scanf("%d%d",&u,&w);
        Add(u,i,w);
    }
    dfs(1,0,0);
    for(int i=1;i<=n;i++)
        printf("%d ",ans[i]);
}