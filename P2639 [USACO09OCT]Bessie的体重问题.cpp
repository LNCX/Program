#include<bits/stdc++.h>
#define N 50005
using namespace std;
int f[N];
int main()
{
    int n,m,i,j,a[N];
    cin>>m>>n;
    for (i=1;i<=n;i++) scanf("%d",&a[i]);
    for (i=1;i<=n;i++)
    {
        for (j=m;j>=a[i];j--)
        f[j]=max(f[j],f[j-a[i]]+a[i]);
        if (f[m]==m) {printf("%d",m); return 0;}
    }
    printf("%d",f[m]);
}
