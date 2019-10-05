#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+5;
int a[N],n,m,k,f[N][N],sum[N];
signed main()
{
    scanf("%lld %lld %lld",&n,&m,&k);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]),sum[i]=sum[i-1]+a[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=k;j++)
        {
            f[i][j]=f[i-1][j];
            if(i>=m) f[i][j]=max(f[i][j],f[i-m][j-1]+sum[i]-sum[i-m]);
        }
    cout<<f[n][k]<<endl;
    return 0;
}