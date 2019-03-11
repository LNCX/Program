#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
ll l,r,ans;
ll f(ll n)
{
    ll t=sqrt(n),sum=0;
    for(int i=1;i<=t;i++)
        sum+=(n/i)%mod;
    (sum*=2)-=pow(t,2);
    sum=((sum%mod+mod)%mod);
    return sum;
}
int main()
{
    cin>>l>>r;
    ans=f(r)-f(l-1);
    cout<<(ans%mod+mod)%mod<<endl;
}