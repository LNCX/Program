#include<bits/stdc++.h>
using namespace std;
const int N=205;
struct edge
{
    int nxt,to;
}e[N*N<<1];
bitset<N>vis;
int head[N],tot,f[N],s[N],ans,m,n;
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