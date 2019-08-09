#include<bits/stdc++.h>
using namespace std;
const int N=2005,maxm=200000;
int n,m;
struct edge
{
    int nxt,to,w;
}e[maxm];
int head[N],tot;
void add(int u,int v,int w)
{
    e[++tot]=(edge){head[u],v,w};
    head[u]=tot;
}
queue<int>q;
int dis[N],v[N];
void SPFA(int s,int t)
{
    memset(dis,0x3f,sizeof(dis));
    dis[s]=0;q.push(s);
    while(!q.empty())
    {
        int u=q.front();q.pop();
        for(int i=head[u];i!=0;i=e[i].nxt)
        {

        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w),add(v,u,w);
    }
    int s,t;
    scanf("%d%d",&t,&s);
    SPFA(s,t);
    return 0;
}