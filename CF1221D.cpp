#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=3e5+5,inf=1e18;
int a[N],b[N],f[N][3];
signed main()
{
    int q;
    scanf("%lld",&q);
    while(q--)
    {
        int n;
        scanf("%lld",&n);
        for(int i=1;i<=n;i++)
            scanf("%lld%lld",&a[i],&b[i]);
        f[1][0]=0,f[1][1]=b[1],f[1][2]=b[1]*2;
        for(int i=2;i<=n;i++)
            for(int j=0;j<=2;j++)
            {
                f[i][j]=inf;
                for(int k=0;k<=2;k++)
                {
                    if(a[i-1]+k==a[i]+j) continue;
                    f[i][j]=min(f[i][j],f[i-1][k]+b[i]*j);
                }
            }
        printf("%lld\n",min({f[n][0],f[n][1],f[n][2]}));
    }
    return 0;
}