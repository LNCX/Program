#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+5,maxm=4e5+5,inf=0x3f3f3f3f;
struct Edge
{
    int to,cap,nxt,flow,from;
}e[maxm];
int tot,head[maxn];
void Add(int from,int to,int cap)
{
    e[++tot].nxt=head[from];
    e[tot].cap=cap;
    e[tot].from=from;
    e[tot].to=to;
    head[from]=tot;
    
    e[++tot].nxt=head[to];
    e[tot].cap=0;
    e[tot].to=from;
    e[tot].from=to;
    head[to]=tot;
}
int a[maxn],p[maxn];
int bfs(int s,int t)
{
    queue<int>q;
    q.push(s);
    memset(a,0,sizeof(a));
    a[s]=inf;
    while(!q.empty())
    {
        int u=q.front();q.pop();
        for(int i=head[u];i!=0;i=e[i].nxt)
        {
            int v=e[i].to;
            if(!a[v]&&e[i].cap>e[i].flow)
            {
                p[v]=i;
                a[v]=min(a[u],e[i].cap-e[i].flow);
                q.push(v);
            }
        }
        if(a[t]) return a[t];
    }
    if(!a[t]) return -1;
    return a[t];
}
int EK(int s,int t)
{
    int add,flow=0;
    while((add=bfs(s,t))!=-1)
    {
        for(int u=t;u!=s;u=e[p[u]].from)
        {
            e[p[u]].flow+=a[t];
            e[p[u]^1].flow-=a[t];
        }
        flow+=a[t];
    }
    return flow;
}
int main()
{
    int n,m,s,t;
    scanf("%d%d%d%d",&n,&m,&s,&t);
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        Add(x,y,z);
    }
    cout<<EK(s,t)<<endl;
    return 0;
}