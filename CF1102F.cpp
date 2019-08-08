#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,oo=0x3f3f3f3f;
int n,m,a[17][N],c1[17][17],c2[17][17],f[1<<17][17];
int cal(int mask, int u)
{
    if(f[mask][u]!=-1) return f[mask][u];
    f[mask][u]=0;
    for(int v=0;v<n;v++)
    {
        if(v == u) continue;
        if((mask >> v) & 1)
            f[mask][u] = max(f[mask][u], min(c1[v][u], cal(mask ^ (1 << u), v)));
    }
    return f[mask][u];
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&a[i][j]);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            c1[i][j]=c2[i][j]=oo;
            for(int k=0;k<m;k++) 
                c1[i][j]=min(c1[i][j],abs(a[i][k]-a[j][k]));
            for(int k=0;k<m-1;k++)
                c2[i][j]=min(c2[i][j],abs(a[i][k]-a[j][k+1]));
        }
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        memset(f,-1,sizeof f);
        for(int j=0;j<n;j++)
            f[1<<j][j]=i==j?oo:0; 
        for(int j=0;j<n;j++)
            ans=max(ans,min(c2[j][i],cal((1<<n)-1,j)));
    }
    cout<<ans<<endl;
    return 0;
}
