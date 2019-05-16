#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f,maxn=250001;
int head[maxn],tot=1,n;
int a[501];
struct edge
{
    int nxt,to,f;
}e[maxn];
void Add(int u,int v,int w)
{
    e[++tot]=(edge){head[u],v,w},head[u]=tot;
    e[++tot]=(edge){head[v],u,w},head[v]=tot;
}
int dep[maxn],f[maxn],cur[maxn];
bool bfs(int s,int t)
{
    memset(dep,0,sizeof(dep));
    queue<int>q;
    q.push(s),dep[s]=1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=head[u];i!=0;i=e[i].nxt)
        {
            int v=e[i].to;
            if(!dep[v]&&e[i].f)
            {
                dep[v]=dep[u]+1;
                q.push(v);
            }
        }
    }
    return dep[t];
}
int dfs(int u,int t,int add)
{
    if(u==t||add==0) return add;
    int flow=0;     
    for(int &i=cur[u];i!=0;i=e[i].nxt)
    {
        int v=e[i].to;
        if(e[i].f<=0||dep[u]+1!=dep[v]) continue;
        int f=dfs(v,t,min(add,e[i].f));
        e[i].f-=f;
        e[i^1].f+=f;
        flow+=f,add-=f;
        if(add==0) break;
    }
    return flow;
}
int dinic(int s,int t)
{
    int flow=0;
    while(bfs(s,t))
    {
        memcpy(cur,head,sizeof(cur));
        while(int add=dfs(s,t,inf))
            flow+=add;
    }
    return flow;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),f[i]=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<i;j++)
          if(a[j]<=a[i])
              f[i]=max(f[i],f[j]+1);
    int len=0;
    for(int i=1;i<=n;i++)
        len=max(len,f[i]);
    cout<<len<<endl;
    int s=0,t=n+n+1;
    for(int i=1;i<=n;i++)
        Add(i,i+n,1);
    for(int i=1;i<=n;i++)
        if(f[i]==1) Add(s,i,1);
    for(int i=1;i<=n;i++)
        if(f[i]==len) Add(i+n,t,1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<i;j++)
          if(a[j]<=a[i]&&f[j]==f[i]-1)
              Add(j+n,i,1);
    int ans=dinic(s,t);
    cout<<ans<<endl;
    Add(1,1+n,inf),Add(s,1,inf);
    if(f[n]==len) Add(n,n+n,inf),Add(n+n,t,inf);
    ans+=dinic(s,t);
    cout<<ans<<endl;
}