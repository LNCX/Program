#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,p,a[3000600];
int main()
{
    scanf("%lld%lld",&n,&p);
    a[1]=1;
    for(int i=2;i<=n;i++)
    {
        a[i]=-(p/i)*a[p%i];
        while(a[i]<0)a[i]+=p;
        printf("%lld\n",a[i-1]);
    }
    printf("%lld\n",a[n]);
    return 0;
}