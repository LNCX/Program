#include<bits/stdc++.h>
using namespace std;
const int N=55,M=1e3+5,inf=0x3f3f3f3f;
int f[M][N][N];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    memset(f,inf,sizeof f);
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        if(f[1][u][v]>w) f[1][u][v]=w;
    }
    for(int l=1;l<=m;l++)
        for(int k=1;k<=n;k++)
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    f[l][i][j]=min(f[l-1][i][k]+f[1][k][j],f[l][i][j]);
    int q;
    cin>>q;
    while(q--)
    {
        int x,y;
        double ans=inf;
        scanf("%d%d",&x,&y);
        for(int l=1;l<=m;l++)
            if( ans*l>f[l][x][y] && f[l][x][y]<inf )
                ans=(double)f[l][x][y]/(double)l;
        ans==inf?puts("OMG!"):printf("%.3lf\n",ans);
    }
    return 0;
}