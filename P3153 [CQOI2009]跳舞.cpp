#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
const int N=2e4+5;
struct net
{
    struct edge
    {
        int nxt,to,f;
    }e[N<<2];
    int head[N],tot=1,dep[N],cur[N];
    void add(int u,int v,int f)
    {
        e[++tot]=(edge){head[u],v,f},head[u]=tot;
        e[++tot]=(edge){head[v],u,0},head[v]=tot;
    }
    bool bfs(int s,int t)
    {
        for(int i=s;i<=t;i++)
            cur[i]=head[i],dep[i]=inf;
        queue<int>q;
        q.push(s),dep[s]=0;
        while(!q.empty())
        {
            int u=q.front();q.pop();
            for(int i=head[u];i!=0;i=e[i].nxt)
            {
                int v=e[i].to;
                if(dep[v]==inf&&e[i].f>0)
                {
                    dep[v]=dep[u]+1;
                    q.push(v);
                }
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
            if(dep[v]==dep[u]+1&&e[i].f>0)
            {
                int f=dfs(v,t,min(add,e[i].f));
                e[i].f-=f,e[i^1].f+=f;
                add-=f,flow+=f;
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
}n1,em;
char c[55][55];
int n,k;
bool check(int x)
{
    n1=em;
    int s=0,t=4*n+1;
    for(int i=1;i<=n;i++)
    {
        n1.add(s,i,x);
        n1.add(i,i+n,k);
        for(int j=1;j<=n;j++)
        {
            if(c[i][j]=='Y') n1.add(i,j+3*n,1);
            else n1.add(i+n,j+2*n,inf);
        }
        n1.add(i+2*n,i+3*n,k);
        n1.add(i+3*n,t,x);
    }
    return n1.dinic(s,t)==x*n;
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%s",c[i]+1);
    int l=0,r=n,ans=-1;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(check(mid)) ans=mid,l=mid+1;
        else r=mid-1;
    }
    cout<<ans<<endl;
    return 0;
}