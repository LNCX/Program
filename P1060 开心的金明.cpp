#include<bits/stdc++.h>
using namespace std;
const int N=505;
int a[N],b[N],c[N],f[N][N];
int main()
{
    int m,n,k;
    scanf("%d%d%d",&m,&n,&k);
    for(int i=1;i<=k;i++)
        scanf("%d%d%d",&a[i],&b[i],&c[i]);
    for(int i=1;i<=n;i++)
      for(int j=m;j>=a[i];j--)
        for(int l=n;l>=b[i];l--)
          f[j][l]=max(f[j][l],f[j-a[i]][l-b[i]]+c[i]);
      cout<<f[m][n]<<endl;
      return 0;
}