#include<bits/stdc++.h>
using namespace std;
const int N=2005,M=2e7+5;
int n,ans,sum[N][N],a[N][N],d[M];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            for(int x=1;x<=i;x++)
                for(int y=1;y<=j;y++)
                    d[sum[i][j]-sum[i][y-1]-sum[x-1][j]+sum[x-1][y-1]]++;
            for(int x=i+1;x<=n;x++)
                for(int y=j+1;y<=n;y++)
                    ans+=d[sum[x][y]-sum[x][j]-sum[i][y]+sum[i][j]];
            for(int x=1;x<=i;x++)
                for(int y=1;y<=j;y++)
                    d[sum[i][j]-sum[i][y-1]-sum[x-1][j]+sum[x-1][y-1]]=0;
            for(int x=1;x<=i;x++)
                for(int y=j+1;y<=n;y++)
                    d[sum[i][y]-sum[x-1][y]-sum[i][j]+sum[x-1][j]]++;
            for(int x=i+1;x<=n;x++)
                for(int y=1;y<=j;y++)
                    ans+=d[sum[x][j]-sum[i][j]-sum[x][y-1]+sum[i][y-1]];
            for(int x=1;x<=i;x++)
                for(int y=j+1;y<=n;y++)
                    d[sum[i][y]-sum[x-1][y]-sum[i][j]+sum[x-1][j]]=0;
        }
    printf("%d\n",ans);
    return 0;
}