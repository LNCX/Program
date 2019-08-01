#pragma GCC optimize("O2")
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,M=2e6+5,inf=0x3f3f3f3f;
class Edge
{
    public:
    int head[N],tot;
    int nxt[M],to[M],w[M];
    void add(int u,int v,int z)
    {
        nxt[++tot]=head[u];
        to[tot]=v;
        w[tot]=z;
        head[u]=tot;
    }
}e1,e2;
int u[N],v[N],w[N],vis[N],dis[N];
int dfn[N],low[N],dfstime,st[N],top,co[N],tot;
void tarjan(int u)
{
    dfn[u]=low[u]=++dfstime;
    st[++top]=u;
    for(int i=e1.head[u];i!=0;i=e1.nxt[i])
    {
        int v=e1.to[i];
        if(!dfn[v])
        {
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(!co[v])
		    low[u]=min(low[u],dfn[v]);
	}
	if(low[u]==dfn[u])
	{
		co[u]=++tot;
		while(st[top]!=u)
		{
			co[st[top]]=tot;
			top--;
		}
		top--;
	}
}
void spfa(int s)
{
    memset(dis,inf,sizeof(dis));
    dis[s]=0;
    queue<int>q;
    q.push(s),vis[s]=1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop(),vis[s]=0;
        for(int i=e2.head[u];i!=0;i=e2.nxt[i])
        {
            int v=e2.to[i],w=e2.w[i];
            if(dis[v]>dis[u]+w)
            {
                dis[v]=dis[u]+w;
                if(!vis[v])
                {
                    q.push(v);
                    vis[v]=1;
                }
            }
        }
    }
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&u[i],&v[i],&w[i]);
        e1.add(u[i],v[i],w[i]);
    }
    tarjan(1);
    for(int i=1;i<=m;i++)
    {
        if(co[u[i]]!=co[v[i]])
            e2.add(co[u[i]],co[v[i]],w[i]);
    }
    spfa(co[1]);
    printf("%d\n",dis[co[n]]);
    return 0;
}