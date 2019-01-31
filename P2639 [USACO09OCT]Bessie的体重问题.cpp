#include<bits/stdc++.h>
#define maxn 50005
using namespace std;
int f[maxn];
int main()
{
    int n,m,i,j,a[maxn];
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
