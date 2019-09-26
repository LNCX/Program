#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,k,a[N];
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    int m=n/2+1;
    for(int i=1;i+m<=n&&k;i++)
    {
        int x=min(k/i,a[m+i]-a[m]);
        a[m]+=x,k-=x*i;
    }
    printf("%d\n",a[m]+k/(n-m+1));
    return 0;
}