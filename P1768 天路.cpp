#include <bits/stdc++.h>
using namespace std;
const int maxn=7e3+5;
double dis[maxn];
int head[maxn],vis[maxn],flag,tot;
struct edge
{
    int to,nxt,v,p;
    double w;
}e[20100];
void spfa(int x)
{
    vis[x]=1;
    for(int i=head[x];i;i=e[i].nxt)
    {
        if(flag) return;
        if(dis[x]+e[i].w<dis[e[i].to])
        {
            dis[e[i].to]=dis[x]+e[i].w;
            if(vis[e[i].to])
            {
                if(dis[e[i].to]<0) flag=1; 
            }
            else spfa(e[i].to);
        }
    }
    vis[x]=0;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    while(m--)
    {
        int a,b,v,p;
        scanf("%d%d%d%d",&a,&b,&v,&p);
        e[++tot]=(edge){b,head[a],v,p,0};
        head[a]=tot;
    }
    double l=0,r=400;
    while(l+0.01<r)
    {
        double mid=(l+r)/2;
        flag=0;
        memset(dis,0,sizeof(dis));
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=tot;i++)
            e[i].w=(double)mid*e[i].p-e[i].v;
        for(int i=1;i<=n;i++)
        {
            spfa(i);
            if(flag) break;
        }
        if(flag) l=mid;
        else r=mid;
    }
    if(l) printf("%.1f\n",r);
    else printf("-1\n");
}