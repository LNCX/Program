#include<bits/stdc++.h>
using namespace std;
int a[105],s[105],f[105][105];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        f[i][i]=a[i];
        s[i]=a[i]+s[i-1];
    }
    for(int i=n-1;i>=1;i--)
        for(int j=i+1;j<=n;j++)
            f[i][j]=max(s[j]-s[i-1]-f[i][j-1],s[j]-s[i-1]-f[i+1][j]);
    printf("%d %d\n",f[1][n],s[n]-f[1][n]);
}
