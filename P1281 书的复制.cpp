#include<bits/stdc++.h>
using namespace std;
const int maxn=505;
int a[maxn],sum[maxn],f[maxn][maxn];
void print(int x,int ans)
{
    if(!x) return;
    for(int i=x;i>=0;i--)
        if(sum[x]-sum[i-1]>ans||!i)
        {
            print(i,ans);
            printf("%d %d\n",i+1,x);
            break;
        }
}
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) 
        scanf("%d",&a[i]);
    for(int i=1;i<=k;i++)
        for(int j=1;j<=n;j++)
            f[i][j]=0x7fffffff;
    for(int i=1;i<=n;i++) 
    {
        sum[i]=sum[i-1]+a[i];
        f[1][i] =sum[i];
    }
    for(int i=2;i<=k;i++)
        for(int j=1;j<=n;j++) 
            for(int k=2;k<=j;k++)
                f[i][j]=min(f[i][j],max(f[i-1][k-1],sum[j]-sum[k-1]));
    print(n, f[k][n]);
    return 0;
}