#include<bits/stdc++.h>
using namespace std;
const int maxn=60,maxm=1005;
struct edge
{
    int nxt,to;
    double w;
}e[maxm];
int n,m,head[maxn],tot,vis[maxn];
struct node
{
   double val,cnt; 
}dis[maxn][maxn];
void SPFA(int s)
{
    queue<int>q;
    for(int i=1;i<=n;i++)
    {
        vis[i]=0;
        dis[s][i].val=-1;
    }
    dis[s][s].val=dis[s][s].cnt=0;
    q.push(s);
    while(!q.empty())
    {
        int u=q.front();
        q.pop(),vis[u]=0;
        for(int i=head[u];i!=0;i=e[i].nxt)
        {
            int v=e[i].to;
            if(dis[s][v].val==-1 || dis[s][v].val/dis[s][v].cnt>(dis[s][u].val+e[i].w)/(dis[s][u].cnt+1))
            {
                dis[s][v].val=dis[s][u].val+e[i].w;
                dis[s][v].cnt=dis[s][u].cnt+1;
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
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        int u,v;
        double w;
        scanf("%d%d%lf",&u,&v,&w);
        e[++tot]=(edge){head[u],v,w},head[u]=tot;
    }
    for(int i=1;i<=n;i++)
        SPFA(i);
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if(dis[x][y].val==-1) puts("OMG!");
        else printf("%.3lf\n",dis[x][y].val/dis[x][y].cnt);
    }
    return 0;
}