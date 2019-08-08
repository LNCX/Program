//遇难则反
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct Edge
{
    int v,nxt;
}e[N];   
int n,m,head[N],tot,ans[N],vis[N],maxx;
void dfs(int u,int maxx)
{
    if(vis[u]) return;
    vis[u]=1;ans[u]=maxx;
    for(int i=head[u];i!=0;i=e[i].nxt)
        dfs(e[i].v,maxx);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        e[++tot].nxt=head[v];
        e[tot].v=u;
        head[v]=tot;
    }
    for(int i=n;i>=1;i--)
        if(!vis[i])
            dfs(i,i);
    for(int i=1;i<=n;i++) 
        printf("%d ",ans[i]);
    puts("");
    return 0;
}