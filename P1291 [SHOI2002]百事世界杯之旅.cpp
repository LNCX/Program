#include<bits/stdc++.h>
typedef long long ll;
ll n,p,q=1,r;
ll gcd(ll a,ll b)
{
    if(a%b==0)
        return b;
    else
        return gcd(b,a%b);
}
int len(ll x)
{
    int p=0;
    while(x>0)
    {
        x/=10;
        p++;
    }
    return p;
}
int main()
{
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++)
    {
        ll a=i/gcd(i,q),b=q/gcd(i,q);
        q*=a,p=p*a+n*b;
        r=gcd(p,q);
        p/=r;q/=r;
    }
    r=p/q;
    if(q==1)
    {
        printf("%lld\n",p);
        return 0;
    }
    for(int i=len(r);i>0;i--)
        putchar(' ');
    printf("%lld\n",p%q);
    if(r>0)
        printf("%lld",r);
    for(int i=len(q);i>0;i--)
        putchar('-');
    putchar('\n');
    for(int i=len(r);i>0;i--)
        putchar(' ');
    printf("%lld\n",q);
    return 0;
}