#include<bits/stdc++.h>
using namespace std;
const int N=2e3+5,maxm=6e3+5;
int t,n,m;
struct Edge
{
    int nxt,to,w;
}e[maxm];
int head[N],tot;
void add(int u,int v,int w)
{
    e[++tot]=(Edge){head[u],v,w};
    head[u]=tot;
}
queue<int>q;
int dis[N],vis[N],cnt[N];
void init()
{
    for(int i=1;i<N;i++)
    {
        dis[i]=0x3f3f3f3f;
        vis[i]=cnt[i]=head[i]=0;
    }
    tot=0;
}
bool SPFA()
{
    q.push(1);
    dis[1]=0;vis[1]=1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();vis[u]=0;
        for(int i=head[u];i!=0;i=e[i].nxt)
        {
            int v=e[i].to,w=e[i].w;
            if(dis[u]+w<dis[v])
            {
                dis[v]=dis[u]+w;
                if(!vis[v])
                {
                    q.push(v);
                    vis[v]=1;cnt[v]++;
                    if(cnt[v]>=n)return true;
                }
            } 
        }
    }
    return false;
}
int main()
{
    cin>>t;
    while(t--)
    {
        init();
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            if(w<0) add(u,v,w);
            else add(u,v,w),add(v,u,w);
        }
        SPFA()?puts("YE5"):puts("N0");
    }
    return 0;    
}