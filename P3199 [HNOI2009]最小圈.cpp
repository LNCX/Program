#include<bits/stdc++.h>
using namespace std;
const int N=3e3+5,M=1e4+5;
const double inf=1e12;
int u[M],v[M],n,m;
double f[N][N],w[M];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
        scanf("%d%d%lf",&u[i],&v[i],&w[i]);
    for(int i=0;i<=n;i++)
        for(int j=1;j<=n;++j)
            f[i][j]=(i?inf:0);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;++j)
            f[i+1][v[j]]=min(f[i+1][v[j]],f[i][u[j]]+w[j]);
    double ans=1e7,ans1;
    for(int i=1;i<=n;i++) 
        if(f[n][i]<1e11)
        {
            ans1=-inf;
            for(int j=0;j<n;++j)
                ans1=max(ans1,(f[n][i]-f[j][i])/(n-j));
            ans=min(ans,ans1);
        }
    printf("%.8lf\n",ans);
    return 0;
}