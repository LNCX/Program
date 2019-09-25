#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5,M=5e3,inf=0x3f3f3f3f;
int n,ans=inf,a[N],b[N],f[N][M<<2];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&a[i],&b[i]);
    memset(f,inf,sizeof(f));
    f[0][0+M]=0;
    for(int i=1;i<=n;i++)
        for(int j=-M;j<=M;j++)
        {
            int dis=a[i]-b[i];
            f[i][j+M]=min(f[i-1][j-dis+M],f[i-1][j+dis+M]+1);
        }
    for(int i=0;i<=M;i++)
    {
        ans=min({f[n][i+M],f[n][-i+M],ans});
        if(ans<=1000)
        {
            cout<<ans<<endl;
            return 0;
        }
    }
    return 0;
}