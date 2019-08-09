#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=105,mod=1000000007;
vector<ll>ans;
ll n,m,a[N];
inline ll read()
{
    ll x=0;
    bool f=true;
    char c=getchar();
    while(!isdigit(c))
    {
        if(c=='-') f=0;
        c=getchar();
    }
    while(isdigit(c))
    {
        x=((x*10)+c-'0')%mod;
        c=getchar();
    }
    return f?x:-x;
}
bool calc(ll x)
{
    ll sum=0;
    for(ll i=n;i>=1;i--)
        sum=((a[i]+sum)*x)%mod;
    sum=(sum+a[0])%mod;
    return !sum;
}
int main()
{
    n=read(),m=read();
    for(int i=0;i<=n;i++)
        a[i]=read();
    for(int i=1;i<=m;i++)
        if(calc(i))
            ans.push_back(i);
    printf("%d\n",ans.size());
    for(auto i:ans)
        printf("%lld\n",i);
    return 0;
}