#include<bits/stdc++.h>
using namespace std;
const int maxn=55,maxm=1e3+5;
int f[maxm][maxn][maxn];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int l=1;l<=m;l++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                f[l][i][j]=1e9;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        if(w<f[1][u][v]) f[1][u][v]=w;
    }
    for(int l=2;l<=m;l++)
        for(int k=1;k<=n;k++)
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    f[l][i][j]=min(f[l-1][i][k]+f[1][k][j],f[l][i][j]);
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int x,y;
        double ans=1e9;
        for(int l=1;l<=m;l++)
            if(ans*l<f[l][x][y])
                ans=(double)f[l][x][y]/l;
        ans==1e9?puts("OMG!"):printf("%lf\n",ans);
    }
    return 0;
}