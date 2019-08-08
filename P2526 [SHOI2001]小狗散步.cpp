#include<bits/stdc++.h>
using namespace std;
const int N=1005;
struct point
{
    int x,y;
}a[N],b[N];
struct edge
{
    int nxt,to;
}e[N*N<<1];
bitset<N>vis;
int head[N],tot=1,f[N],g[N],ans;
void add(int u,int v)
{
    e[++tot]=(edge){head[u],v},head[u]=tot;
}
bool dfs(int u)
{
    for(int i=head[u];i!=0;i=e[i].nxt)
    {
        int v=e[i].to;
        if(vis[v]) continue;
        vis[v]=1;
        if(!f[v]||dfs(f[v]))
        {
            f[v]=u,g[u]=v;
            return true;
        }
    }
    return false;
}
double dis(point a,point b)
{
    return sqrt((double)(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&a[i].x,&a[i].y);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&b[i].x,&b[i].y);
        for(int j=1;j<n;j++)
            if(2*dis(a[j],a[j+1])>=dis(a[j],b[i])+dis(b[i],a[j+1]))
                add(j,i);
    }
    for(int i=1;i<n;i++)
    {
        vis.reset();
        ans+=dfs(i);
    }
    cout<<ans+n<<endl;
    for(int i=1;i<=n;i++)
    {
        printf("%d %d ",a[i].x,a[i].y);
        if(g[i]) printf("%d %d ",b[g[i]].x,b[g[i]].y);
    }
}