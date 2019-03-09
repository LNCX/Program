#include<bits/stdc++.h>
using namespace std;
const int maxn=305;
bool vis[maxn];
vector<int>s[maxn];
int n,p,ans=0x7fffffff;
int size[maxn],dep[maxn],head[maxn],tot;
struct Edge
{
    int nxt,to;
}e[maxn<<1];
void add(int u,int v)
{
    e[++tot]=(Edge){head[u],v};
    head[u]=tot;
}
void init(int u,int fa)
{
    dep[u]=dep[fa]+1;
    s[dep[u]].push_back(u);
    size[u]=1;
    for(int i=head[u];i!=0;i=e[i].nxt)
    {
        int v=e[i].to;
        if(v==fa) continue;
        init(v,u);
        size[u]+=size[v];
    }
}
void hit(int u,bool flag)
{
    vis[u]=flag;
    for(int i=head[u];i!=0;i=e[i].nxt)
    {
        int v=e[i].to;
        if(dep[v]>dep[u])
            hit(v,flag);
    }
}
void dfs(int dep,int now)
{
    ans=min(ans,now);
    for(int i=0;i<(int)s[dep].size();i++)
    {
        int v=s[dep][i];
        if(!vis[v])
        {
            hit(v,1);
            dfs(dep+1,now-size[v]);
            hit(v,0);
        }
    }
}
int main()
{
    scanf("%d%d",&n,&p);
    while(p--)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v),add(v,u);
    }
    init(1,0);
    dfs(2,n);
    printf("%d\n",ans);
    return 0;
}
