#include<bits/stdc++.h>
using namespace std;
const int maxn=201;
int a[maxn],dp[maxn][maxn][maxn],sum[maxn];
int main()
{
    int t;
    cin>>t;
    for(int o=1;o<=t;++o)
    {
        int n;
        scanf("%d",&n);
        memset(dp,0,sizeof(dp));
        memset(sum,0,sizeof(sum));
        for(int i=1;i<=n;++i)
            scanf("%d",&a[i]);
        for(int i=n-1;i>0;i--)
            for(int j=i+1;j<=n;j++)
                if(a[i] == a[j])
                    sum[i]++;
        for(int i=n;i>0;i--)
            for(int j=i;j<=n;j++)
            {
                for(int p=i;p<j;p++)
                    if(a[p]==a[j])
                        for(int k=0;k<=sum[j];++k)
                            dp[i][j][k]=max(dp[i][j][k],dp[p+1][j-1][0]+dp[i][p][k+1]);
                for(int k=0;k<=sum[j];k++)
                    dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][0]+(k+1)*(k+1));
            }
        printf("Case %d: %d\n" ,o,dp[1][n][0]);
    }
    return 0;
}