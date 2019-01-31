#include<cstdio>
using namespace std;
int max(int a,int b){return a>b?a:b;}
int a[51][51];
int sum[51][51][51][51];
int m,n,i,j,h,k,x,y,z;
int main()
{
    scanf("%d%d",&m,&n);
    for(i=1;i<=m;i++)
    for(j=1;j<=n;j++)
    	scanf("%d",&a[i][j]);
    for(i=1;i<=m;i++)
    for(j=1;j<=n;j++)
    for(h=1;h<=m;h++)
    for(k=1;k<=n;k++)
    {
        int temp1=max(sum[i-1][j][h-1][k],sum[i][j-1][h][k-1]);
        int temp2=max(sum[i-1][j][h][k-1],sum[i][j-1][h-1][k]);
        sum[i][j][h][k]=max(temp1,temp2)+a[i][j];
        if(i!=h&&j!=k) sum[i][j][h][k]+=a[h][k];
    }
    printf("%d\n",sum[m][n][m][n]);
    return 0;
}
