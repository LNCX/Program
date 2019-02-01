#include<bits/stdc++.h>
using namespace std;
inline int read()
{
    int x=0;
    char c=getchar();
    while(c<'0'||'9'<c)
        c=getchar();
    while('0'<=c&&c<='9')
    {
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x;
}
const int maxn=1e5+5,maxm=2e5+5,inf=0x3f3f3f3f;
struct Edge
{
    int to,cap,nxt,flow,from;
}e[maxm];
int tot,head[maxn];
void Add(int from,int to,int cap)
{
    e[++tot].nxt=head[from];
    e[tot].cap=cap;
    e[tot].to=to;
    head[from]=tot;
    
    e[++tot].nxt=head[to];
    e[tot].cap=0;
    e[tot].to=from;
    head[to]=tot;
}
queue<int>q;
int a[maxn],p[maxn];
int bfs(int s,int t)
{
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
}
int EK(int s,int t)
{
    int add,flow=0;
    while(add=bfs(s,t)!=-1)
    {
        if(!a[t]) break;
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
    int n=read(),m=read(),s=read(),t=read();
    for(int i=1;i<=m;i++)
        Add(read(),read(),read());
    cout<<EK(s,t)<<endl;
    return 0;
}