#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,maxm=5e5+5;
struct edge
{
    int nxt,to;
}e[maxm];
int head[N],tot,dfn[N],low[N],st[N],top,col[N],dfstime,d[N],ans;
void tarjan(int u)
{
    low[u]=dfn[u]=++dfstime;
    st[++top]=u;
    for(int i=head[u];i!=0;i=e[i].nxt)
    {
        int v=e[i].to;
        if(!dfn[v])
        {
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(!col[v]) low[u]=min(low[u],dfn[v]);
    }
    if(low[u]==dfn[u])
    {
        ++col[0];
        while(st[top]!=u)
            col[st[top--]]=col[0];
        col[st[top--]]=col[0];
    }
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        e[++tot]=(edge){head[u],v},head[u]=tot;
    }
    for(int i=1;i<=n;i++)
        if(!dfn[i])
            tarjan(i);
    for(int u=1;u<=n;u++)
        for(int i=head[u];i!=0;i=e[i].nxt)
            if(col[e[i].to]!=col[u])
                d[col[e[i].to]]++;
    for(int i=1;i<=col[0];i++)
        if(d[i]==0) ans++;
    cout<<ans<<endl;
    return 0;
}
