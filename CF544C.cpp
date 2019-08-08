#include<bits/stdc++.h>
using namespace std;
const int N=505;
int a[N],f[N][N]={1};
int main()
{
    int n,m,b,mod;
    scanf("%d%d%d%d",&n,&m,&b,&mod);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            for(int k=a[i];k<=b;k++)
                f[j][k]=(f[j][k]+f[j-1][k-a[i]])%mod;
    int ans=0;
    for(int i=0;i<=b;i++)
        ans=(ans+f[m][i])%mod;
    cout<<ans<<endl;
    return 0;
}