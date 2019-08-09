#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e6+5;
LL a[N],c[N];
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        LL sum=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&a[i]);
            sum+=a[i];
        }
        LL m=sum/n;
        c[0]=0;
        for(int i=1;i<=n;i++)
            c[i]=c[i-1]+a[i]-m;
        sort(c,c+n);
        LL x=c[n/2],ans=0;
        for(int i=0;i<n;i++)
            ans+=abs(x-c[i]);
        printf("%lld\n",ans);
    }
}