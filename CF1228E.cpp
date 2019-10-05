#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=255,mod=1e9+7;
int n,m,f[N][N],C[N][N],pow1[N]={1},pow2[N]={1};
inline int mo(int x){return x>=mod?x-mod:x;}
signed main()
{
    scanf("%lld%lld",&n,&m);
    for(int i=0;i<=n;i++)
    {
        C[i][0]=1;
        for(int j=1;j<=i;j++) 
            C[i][j]=mo(C[i-1][j]+C[i-1][j-1]);
    }
    for(int i=1;i<=n;i++)
    {
        pow1[i]=m*pow1[i-1]%mod;
        pow2[i]=(m-1)*pow2[i-1]%mod;
    }
    for(int i=1;i<=n;i++)
        f[1][i]=(C[n][i]*pow2[n-i])%mod;
    for(int i=2;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=0;k<=j;k++)
            {
                int x=C[n-k][j-k]*f[i-1][k]%mod,y=pow1[k]*pow2[n-j]%mod;
                f[i][j]=mo(f[i][j]+x*y%mod);
                if(j==k) f[i][j]=mo(f[i][j]-1ll*pow2[n]*f[i-1][k]%mod+mod);
            }
    cout<<f[n][n]<<endl;
    return 0;
}