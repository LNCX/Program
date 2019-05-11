#include<bits/stdc++.h>
using namespace std;
const int maxn=2e4+5;
int f[maxn][2],t[maxn];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&t[i]);
    for(int i=1;i<=n+2;i++)
    {
        f[i][1]=min(f[i-1][0],f[i-1][1])+t[i];
        f[i][0]=min(f[i-1][1],f[i-2][1]);
    }
    int ans=0x7fffffff;
    for(int i=n;i<=n+2;i++)
    {
        if(f[i][0]<ans) ans=f[i][0];
        if(f[i][1]<ans) ans=f[i][1];
    }
    printf("%d\n",ans);
    return 0;
}