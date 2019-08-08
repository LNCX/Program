#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2001;
const LL mod=1e9+7;
LL up[N][N],down[N][N],he[N];
int main() 
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=2;i<=m;i++) up[1][i]=1;
    for(int i=2;i<=n;i++) 
    {
        for(int j=2;j<=m;j++) up[i][j]=(up[i][j-1]+up[i-1][j])%mod;
        for(int j=2;j<=m;j++) up[i][j]=(up[i][j]+up[i][j-1])%mod;
        for(int j=2;j<=m;j++) up[i][j]=(up[i][j]+1)%mod;
    }
    for(int i=2;i<=m;i++) down[n][i]=1;
    for(int i=n-1;i>=1;i--) 
    {
        for(int j=2;j<=m;j++) down[i][j]=(down[i][j-1]+up[n-i][j])%mod;
        for(int j=2;j<=m;j++) down[i][j]=(down[i][j]+down[i][j-1])%mod;
        for(int j=2;j<=m;j++) down[i][j]=(down[i][j]-up[n-i][j]+1)%mod;
    }
    LL ans=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            ans=(ans+((up[i][j]*down[i][j])%mod*(m-j+1))%mod)%mod;
    printf("%lld\n",ans);
}