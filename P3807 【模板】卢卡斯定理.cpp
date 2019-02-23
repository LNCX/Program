#include<bits/stdc++.h>
using namespace std;
long long n,m,p;
long long power(long long a,long long b)
{
    long long ans=1;
    while(b)
    {
        if(b&1) ans=ans*a%p;
        a=a*a%p;
        b>>=1;
    }
    return ans;
}
long long C(long long n,long long m)
{
    if(m>n) return 0;
    long long a=1,b=1;
    for(long long i=n-m+1;i<=n;i++) a=a*i%p;
    for(long long i=2;i<=m;i++) b=b*i%p;
    return a*power(b,p-2)%p;
}
long long Lucas(long long n,long long m)
{
    if(!m) return 1;
    return (C(n%p,m%p)*Lucas(n/p,m/p))%p;
}
int main()
{
    long long t;
    cin>>t;
    while(t--)
    {
        scanf("%lld%lld%lld",&n,&m,&p);
        printf("%lld\n",Lucas(n+m,m));
    }
    return 0;
}