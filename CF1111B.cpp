#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=1e5+5;
double ans;
LL a[maxn],sum[maxn],tot;
int main()
{
    LL n,k,m;
    cin>>n>>k>>m;
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    {
        sum[i]=sum[i-1]+a[i];
        tot+=a[i];
    }
    for(int i=0;i<=min(n-1,m);i++)
    {
        LL x=tot-sum[i];
        x+=min(k*(n-i),m-i);
        ans=max((double)x/(n-i),ans);
    }
    printf("%.10lf\n",ans);
    return 0;
}