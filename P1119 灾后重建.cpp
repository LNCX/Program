#include<bits/stdc++.h>
using namespace std;
const int N=205,oo=0x3f3f3f3f;
int q,n,m,dis[N][N],a[N];
int main()
{
    memset(dis,oo,sizeof(dis));
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        dis[u][v]=dis[v][u]=w;
    }
    for(int i=0;i<n;i++)
        dis[i][i]=0;
    scanf("%d",&q);
    int k=0;
    for(int i=1;i<=q;i++)
    {
        int x,y,t;
        scanf("%d%d%d",&x,&y,&t);
        while(a[k]<=t&&k<n)
        {
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
            k++;
        }
        if(dis[x][y]==oo||a[x]>t||a[y]>t)
            puts("-1");
        else printf("%d\n",dis[x][y]);
    }
    return 0;
}