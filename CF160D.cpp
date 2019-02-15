#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int n,m,f[maxn],head[maxn],tot,ans[maxn];
int dfn[maxn],low[maxn],dfstime,vis[maxn];//none:0; at least :1;  any:2
struct Edge1
{
    int u,v,w,num,ans;
    bool operator<(const Edge1 &x)const
    {
        return w<x.w ;
    }
}e[maxn];
struct Edge2
{
    int v,nxt,id;
}e2[maxn];
void add(int u,int v,int id)
{
    e2[++tot].nxt=head[u];
    e2[tot].v=v;
    e2[tot].id=id;
    head[u]=tot;
}
int find(int x)
{
    if(x==f[x]) return x;
    f[x]=find(f[x]);
    return f[x];
}
void Tarjan(int u,int fa)
{
    low[u]=dfn[u]=++dfstime;vis[u]=1;
    for(int i=head[u];i!=-1;i=e2[i].nxt)
    {
        if((i^1)==fa) continue;
        int v=e2[i].v;
        if(vis[v])
        {
            low[u]=min(low[u],dfn[v]);
            continue;
        }
        Tarjan(v,i);
        low[u]=min(low[u],low[v]);
        if(low[v]==dfn[v]) e[e2[i].id].ans=2;
    }
}
void deal(int l,int r)
{
    tot=-1;
    for(int i=l;i<=r;i++)
        head[find(e[i].u)]=head[find(e[i].v)]=-1;
    for(int i=l;i<=r;i++)
    {
        int x=find(e[i].u),y=find(e[i].v);
        if(x==y)
        {
            e[i].ans=0;
            continue;
        }
        e[i].ans=1;
        vis[x]=vis[y]=0;
        add(x,y,i),add(y,x,i);
    }
    dfstime=0;
    for(int i=l;i<=r;i++)
        if(find(e[i].u)!=find(e[i].v)&&!vis[find(e[i].u)])
            Tarjan(find(e[i].u),-1);
}
void kruskal()
{
    for(int i=1;i<=n;i++)
        f[i]=i;
    for(int i=1;i<=m;)
    {
        int j=i;
        while(j<=m&&e[j].w==e[i].w) j++;
        deal(i,j-1);
        for(int k=i;k<=j-1;k++)
        {
            int x=find(e[k].u),y=find(e[k].v);
            if(x==y) continue;
            f[x]=y;
        }
        i=j;
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
        scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w),e[i].num=i;
    sort(e+1,e+1+m);
    kruskal();
    for(int i=1;i<=m;i++)
        ans[e[i].num]=e[i].ans;
    for(int i=1;i<=m;i++)
        if(ans[i]==0)
            puts("none");
        else if(ans[i]==1)
            puts("at least one");
        else puts("any");
    return 0;
}