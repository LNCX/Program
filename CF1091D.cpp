#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=1000010;
const LL mod=998244353;
LL s[maxn],f[maxn];
int main()
{
    LL n;
    scanf("%lld",&n);
    f[0]=1,s[n]=1;
    for(LL i=1;i<=n;i++)
        f[i]=(f[i-1]*i)%mod;
    for(LL i=n-1;i>=1;i--)
        s[i]=(s[i+1]*(i+1))%mod;
    LL ans=(n*(f[n]))%mod;
    for(LL i=1;i<=n-1;i++)
        ans=(ans-s[i]+mod)%mod;
    cout<<ans<<endl;
}