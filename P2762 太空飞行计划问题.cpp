#include<bits/stdc++.h>
using namespace std;
const int N=505,inf=0x3f3f3f3f;
struct edge
{
    int nxt,to,f;
}e[N<<1];
int head[N],tot=1,dep[N],cur[N],ans;
void add(int u,int v,int f)
{
    e[++tot]=(edge){head[u],v,f},head[u]=tot;
    e[++tot]=(edge){head[v],u,0},head[v]=tot;
}
bool bfs(int s,int t)
{
    for(int i=s;i<=t;i++)
    {
        dep[i]=inf;
        cur[i]=head[i];
    }
    queue<int>q;
    q.push(s),dep[s]=0;
    while(!q.empty())
    {
        int u=q.front();q.pop();
        for(int i=head[u];i!=0;i=e[i].nxt)
        {
            int v=e[i].to;
            if(dep[v]!=inf||e[i].f<=0) continue;
            dep[v]=dep[u]+1;
            q.push(v);
        }
    }
    return dep[t]!=inf;
}
int dfs(int u,int t,int add)
{
    if(add==0||u==t) return add;
    int flow=0;
    for(int &i=cur[u];i!=0;i=e[i].nxt)
    {
        int v=e[i].to;
        if(dep[u]+1==dep[v]&&e[i].f>0)
        {
            int f=dfs(v,t,min(add,e[i].f));
            e[i].f-=f,e[i^1].f+=f;
            flow+=f,add-=f;
            if(add==0) break;
        }
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
int main()
{
    int m,n;
    scanf("%d%d",&m,&n);
    int s=0,t=n+m+1,x;
    string line;
    getline(cin,line);
    for(int i=1;i<=m;i++)
    {
        getline(cin,line);
        stringstream ss(line);
        ss>>x,ans+=x;
        add(s,i,x);
        while(ss>>x)
            add(i,x+m,inf);
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        add(i+m,t,x);
    }
    x=dinic(s,t);
    for(int i=1;i<=m;i++)
        if(dep[i]!=inf)
            printf("%d ",i);
    puts("");
    for(int i=m+1;i<t;i++)
        if(dep[i]!=inf)
            printf("%d ",i-m);
    puts("");
    cout<<ans-x<<endl;
    return 0;
}