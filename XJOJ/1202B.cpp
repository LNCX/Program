#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[85]={1,2},ans=0,N=1e6;
ll search(ll x)
{
    ll l=0,r=71,res=0;
    while(l<=r)
    {
        ll mid=(l+r)>>1;
        if(f[mid]<=x) res=mid,l=mid+1;
        else r=mid-1; 
    }
    return res;
}
ll solve1(ll n)
{
    ll res=0;
    while(n)
    {
        ll x=search(n);
        res|=(1ll<<x);
        n-=f[x];
    }
    return res;
}
int main()
{
    ll a,b;
    cin>>a>>b;
    for(int i=2;i<=71;i++)
        f[i]=f[i-1]+f[i-2];
    for(ll i=a;i<=b;i++)
        ans^=solve1(i);
    cout<<ans<<endl;
}