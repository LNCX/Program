#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=35,mod=1000000007;
ll a[N];
map<ll,ll>s,t;
int main()
{
    ll n,p,c;
    scanf("%lld%lld%lld",&n,&p,&c);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++)
    {
        t=s;
        t[a[i]]++;
        for(auto it=s.begin();it!=s.end();it++)
            (t[ (a[i] * it->first)%p ]+=it->second )%=mod;
        s=t; 
    }
    printf("%lld\n",s[c]);
}