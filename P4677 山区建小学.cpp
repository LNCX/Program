#include<bits/stdc++.h>
using namespace std;
const int N=505,inf=0x3f3f3f3f;
int n,m,a[N],sum[N],f[N][N],s[N][N];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=2;i<=n;i++)
        scanf("%d",&a[i]),a[i]+=a[i-1];
    for(int l=1;l<=n;l++)
        for(int r=l;r<=n;r++)
        {
            int mid=l+r>>1;
            for(int k=l;k<=r;k++)
                s[l][r]+=abs(a[k]-a[mid]);
        }
    memset(f,inf,sizeof(f));
    f[0][0]=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m&&j<=i;j++)
            for(int k=j-1;k<i;k++)
                f[i][j]=min(f[k][j-1]+s[k+1][i],f[i][j]);
    printf("%d\n",f[n][m]);
    return 0;
}