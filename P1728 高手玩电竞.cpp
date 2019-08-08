#include<bits/stdc++.h>
using namespace std;
const int N=52,maxm=2505;
int n,m,a[N][N],f[N][N][maxm],ans;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=n;i>=1;i--) 
        for(int j=1;j<=i;j++)
            scanf("%d",&a[i][j]),a[i][j]+=a[i+1][j+1];
    memset(f,-0x3f3f3f3f,sizeof f);
    f[0][0][0]=0;
    for(int i=1;i<=n;i++)
    {
        for(int k=0;k<=m;k++)
            f[i][0][k]=f[i-1][0][k];
        for(int j=0;j<=i;j++) 
            for(int k=j;k<=m;k++)
            {
                for(int t=max(j-1,0);t<=i-1;t++) 
                    f[i][j][k]=max(f[i][j][k],f[i-1][t][k-j]);
                f[i][j][k]+=a[n-j+1][i-j+1]; 
                ans=max(ans,f[i][j][k]);
            }
    }
    printf("%d\n",ans);
    return 0;
}