#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL mod=1e6+3;
LL power(LL a,LL b)
{
    LL ans=1;
    while(b!=0)
    {
        if(b&1) ans=(ans*a)%mod;
        b>>=1;a=(a*a)%mod;
    }
    return ans;
}
int main()
{
    LL n;
    scanf("%lld",&n);
    if(n==0) puts("1");
    else printf("%lld\n",power(3,n-1));
    return 0;
}