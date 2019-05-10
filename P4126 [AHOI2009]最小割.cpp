#include<bits/stdc++.h>
using namespace std;
const int maxn=4e3+5,maxm=6e4+5,inf=0x3f3f3f3f;
struct edge
{
    int from,nxt,to,f;
}e[maxm<<1];
int n,m,head[maxn],cur[maxn],tot=1,dep[maxn];
void Add(int u,int v,int f)
{
    e[++tot]=(edge){u,head[u],v,f};
    head[u]=tot;
    e[++tot]=(edge){v,head[v],u,0};
    head[v]=tot;
}
bool bfs(int s,int t)
{
    memset(dep,inf,sizeof(dep));
    for(int i=0;i<=n;i++)
        cur[i]=head[i];
    queue<int>q;
    dep[s]=0,q.push(s);
    while(!q.empty())
    {
        int u=q.front();q.pop();
        for(int i=head[u];i!=0;i=e[i].nxt)
        {
            int v=e[i].to,f=e[i].f;
            if(dep[v]!=inf||f<=0) continue;
            dep[v]=dep[u]+1;
            q.push(v);
        }
    }
    return dep[t]!=inf;
}
int dfs(int u,int t,int add)
{
    if(u==t||add==0) return add;
    int flow=0;
    for(int &i=cur[u];i!=0;i=e[i].nxt)
    {
        int v=e[i].to,res=e[i].f;
        if(dep[v]!=dep[u]+1||res<=0) continue;
        int f=dfs(v,t,min(add,res));
        add-=f,flow+=f;
        e[i].f-=f,e[i^1].f+=f;
        if(add==0) break;
    } 
    return flow;
}
int dinic(int s,int t)
{
    int flow=0;
    while(bfs(s,t))
        flow+=dfs(s,t,inf);
    return flow;
}
stack<int>st;
int dfn[maxn],low[maxn],dfstime,col[maxn],num;
void tarjan(int u)
{
    st.push(u);
    low[u]=dfn[u]=++dfstime;
    for(int i=head[u];i!=0;i=e[i].nxt)
    {
        int v=e[i].to,f=e[i].f;
        if(f==0) continue;
        if(!dfn[v])
        {
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(!col[v]) low[u]=min(low[u],dfn[v]);
    }
    if(low[u]==dfn[u])
    {
        col[u]=++num;
        while(st.top()!=u)
        {
            col[st.top()]=num;
            st.pop();
        }
        st.pop();
    }
}
int main()
{
    int s,t;
    scanf("%d%d%d%d",&n,&m,&s,&t);
    while(m--)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        Add(u,v,w);
    }
    dinic(s,t);
    for(int i=1;i<=n;i++)
        if(!dfn[i])
            tarjan(i);
    for(int i=2;i<tot;i+=2)
    {
        int u=e[i].from,v=e[i].to,f=e[i].f;
        if(col[u]!=col[v]&&f==0)
        {
            printf("1 ");
            if(col[u]==col[s]&&col[v]==col[t]) puts("1");
            else puts("0");
        }
        else puts("0 0");
    }
    return 0;
}