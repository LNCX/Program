#include<bits/stdc++.h>
using namespace std;
const int maxn=105,mod=1000007;
int a[maxn],f[maxn][maxn];//f[i][j]+=f[i-1][j-k]|k=0~min(a[i],j)
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<=m;i++)
        f[i][0]=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            for(int k=j;k>=j-a[i]&&k>=0;k--)
                f[i][j]=(f[i][j]+f[i-1][k])%mod;
    printf("%d",f[n][m]);
    return 0;
}