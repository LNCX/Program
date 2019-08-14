#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll gcd(ll a,ll b)
{
    if(b==0) return a;
    else return gcd(b,a%b);
}
int main()
{
    scanf("%lld%lld",&n,&m);
    ll x=gcd(n,m);
    n/=x,m/=x;
    int q;
    scanf("%d",&q);
    while (q--)
    {
        ll a,b,c,d;
        scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
        b--,d--;
        a==1?b/=n:b/=m;
        c==1?d/=n:d/=m;
        b==d?puts("YES"):puts("NO");
    }
    return 0;
}