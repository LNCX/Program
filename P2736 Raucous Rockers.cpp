#include<bits/stdc++.h>
using namespace std;
int n,m,t,ans,x,f[25][25];
int main()
{
    scanf("%d%d%d",&n,&t,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        for(int j=m;j>=1;j--)
            for(int k=t;k>=x;k--)
            {
                f[j][k]=max(f[j][k],max(f[j-1][t]+1,f[j][k-x]+1));
                ans=max(ans,f[j][k]);
            }
    }
    printf("%d\n",ans);
    return 0;
}