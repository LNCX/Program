#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e6+5;
int pri[N],phi[N];
ll sphi[N],p,n,inv;
bool vis[N];
unordered_map<ll,ll>ansphi;
ll pw(ll a,ll b)
{
    ll res=1;
    while(b)
    {
        if(b&1)
            (res*=a)%=p;
        (a*=a)%=p;
        b>>=1;
    }
    return res;
}
void init()
{
    int tot=0;
    inv=pw(6,p-2);
    phi[1]=1;
    for(int i=2;i<N;i++)
    {
        if(!vis[i]){pri[++tot]=i;phi[i]=i-1;}
        for(int j=1;j<=tot&&i*pri[j]<N;j++)
        {
            vis[i*pri[j]]=true;
            if(i%pri[j]==0){phi[i*pri[j]]=phi[i]*pri[j];break;}
            phi[i*pri[j]]=phi[i]*(pri[j]-1);
        }
    }
    for(int i=1;i<N;i++)
        sphi[i]=(sphi[i-1]+1LL*i*i%p*phi[i]%p)%p;
}
ll s2(ll x)
{
    x%=p;
    return x*(x+1)%p*(2*x+1)%p*inv%p;
} 
ll s3(ll x)
{
    x%=p;
    return (x*(x+1)/2)%p*((x*(x+1)/2)%p)%p;
}
ll calc(ll x)
{
    if(x<N)
        return sphi[x];
    if(ansphi[x])
        return ansphi[x];
    ll r,res=s3(x);
    for(ll l=2;l<=x;l=r+1)
    {
        r=x/(x/l);
        (res-=1LL*(s2(r)-s2(l-1)+p)%p*calc(x/l)%p)%=p;
    }
    (res+=p)%=p;
    return ansphi[x]=res;
}
ll solve()
{
    ll r,res=0;
    for(ll l=1;l<=n;l=r+1)
    {
        r=n/(n/l);
        (res+=1LL*(calc(r)-calc(l-1)+p)%p*s3(n/l)%p)%=p;
    }
    (res+=p)%=p;
    return res;
}
int main()
{
    scanf("%lld%lld",&p,&n);
    init();
    printf("%lld\n",solve());
    return 0;
}