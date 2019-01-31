#include<bits/stdc++.h>
using namespace std;
const int inf=0x7fffffff;
bool v1[5005];
int v2[5005],tot=1;
int cost[5005][5005],minn,n,m,ans,now;
void read()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            cost[i][j]=inf;
        }
    for(int i=1,u,v,w;i<=m;i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        if(cost[u][v]>w)
            cost[u][v]=cost[v][u]=w;
    }
    for(int i=1;i<=n;i++)
        v2[i]=cost[1][i];
    v1[1]=1;
}
int prim()
{
    while(tot<n)
    {
        minn=inf; 
        tot++;
        for(int i=1;i<=n;i++)
            if(!v1[i]&&v2[i]<minn)
            {
                minn=v2[i];
                now=i;
            }
        printf("%d\n",ans);
        ans+=minn;
        for(int i=1;i<=n;i++)
            if(v2[i]>cost[now][i]&&!v1[i])
            {
                v2[i]=cost[now][i];
            }
        v1[now]=1;
    }
}
int main()
{
    read();
    prim();
    printf("%d",ans);
}
