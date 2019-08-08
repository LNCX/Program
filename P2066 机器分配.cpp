#include<bits/stdc++.h>
using namespace std;
const int N=20;
int a[N][N],f[N][N],pre[N][N][N];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    for(int i=1;i<=n;i++)
        for(int j=0;j<=m;j++)
            for(int k=0;k<=j;k++)
                if(f[i][j]<f[i-1][k]+a[i][j-k])
                {
                    f[i][j]=f[i-1][k]+a[i][j-k];
                    for(int h=1;h<i;h++) pre[i][j][h]=pre[i-1][k][h];
                    pre[i][j][i]=j-k;
                }
    cout<<f[n][m]<<endl;
    for(int i=1;i<=n;i++)
        printf("%d %d\n",i,pre[n][m][i]);
    return 0;
}