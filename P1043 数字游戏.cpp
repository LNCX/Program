#include<bits/stdc++.h>
#define mod(x) ((x%10+10)%10)
using namespace std;
int a[105],sum[105],maxx[105][105][10],minx[105][105][10];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        a[i+n]=a[i];
    }
    for(int i=1;i<=2*n;i++)
        sum[i]=sum[i-1]+a[i];
    for(int i=1;i<=2*n;i++)
        for(int j=i;j<=2*n;j++)
            maxx[i][j][1]=minx[i][j][1]=mod(sum[i]-sum[j-1]);
    for(int len=1;len<=2*n;len++)
        for(int l=1;l+len<=2*n;l++)
            for(int k=l;k<=l+len;k++)
                for(int i=2;i<=m;i++)
                {
                    maxx[l][l+len][i]=max(f[l][k][i-1],())
                }
    return 0;
}