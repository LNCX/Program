#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N],f[N],g[N];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        f[i]=g[max(0,i-a[i])]+1;
        g[i]=max(g[i-1],f[i]);
    }
    printf("%d",f[n]);
    return 0;
}