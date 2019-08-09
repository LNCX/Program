#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2001,mod=1e9+7;
LL a[N][N],b[N][N];
//a[i][j]:第i行两个黑格相距离为j的上方不下降总数
//b[i][j]:反之
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=2;i<=m;i++) 
        a[1][i]=1;
    for(int i=2;i<=n;i++)
    {
        for(int j=2;j<=m;j++)
            a[i][j]=(a[i][j-1]+a[i-1][j])%mod;
        for(int j=2;j<=m;j++)
            a[i][j]=(a[i][j]+a[i][j-1])%mod;
        for(int j=2;j<=m;j++)
            a[i][j]=(a[i][j]+1)%mod;
    }
    for(int i=2;i<=m;i++) b[n][i]=1;
    for(int i=n-1;i>=1;i--)
    {
        for(int j=2;j<=m;j++)
            b[i][j]=(b[i][j-1]+a[n-i][j])%mod;
        for(int j=2;j<=m;j++)
            b[i][j]=(b[i][j]+b[i][j-1])%mod;
        for(int j=2;j<=m;j++)
            b[i][j]=(b[i][j]-a[n-i][j]+1)%mod;
    }
    LL ans=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            ans=(ans+((a[i][j]*b[i][j])%mod*(m-j+1))%mod)%mod;
    printf("%I64d\n",ans);
}