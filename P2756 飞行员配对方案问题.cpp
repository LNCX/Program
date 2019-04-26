#include<bits/stdc++.h>
using namespace std;
const int maxn=205;
struct edge
{
    int nxt,to;
}e[maxn*maxn<<1];
bitset<maxn>vis;
int head[maxn],tot,f[maxn],s[maxn],ans,m,n;
void add(int u,int v)
{
    e[++tot]=(edge){head[u],v};
    head[u]=tot;
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
            f[v]=u,s[u]=v;
            return true;
        }
    }
    return false;
}
int main()
{
    scanf("%d%d",&m,&n);
    while(1)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add(x,y),add(y,x);
        if(x==-1&&y==-1) break;
    }
    for(int i=1;i<=m;i++)
    {
        vis.reset();
        ans+=dfs(i);
    }
    m==0?puts("No Solution!"):printf("%d\n",ans);
    for(int i=1;i<=m;i++) if(s[i])
        printf("%d %d\n",i,s[i]);
    return 0;
}