#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=5000000;
int v[maxn+10],p[maxn+10];
LL mu[maxn+10],phi[maxn+10];
inline void init()
{
    v[1]=mu[1]=phi[1]=1;
    int tot=0;
    for(int i=2;i<=maxn;++i)
    {
        if (!v[i]) p[++tot]=i,mu[i]=-1,phi[i]=i-1;
        for(int j=1;j<=tot&&i*p[j]<=maxn;++j)
        {
            v[i*p[j]]=1;
            if(i%p[j]) mu[i*p[j]]=-mu[i],phi[i*p[j]]=phi[i]*phi[p[j]];
            else {mu[i*p[j]]=0,phi[i*p[j]]=phi[i]*p[j];break;}
        }
    }
    for(int i=1;i<=maxn;++i)
        mu[i]+=mu[i-1],phi[i]+=phi[i-1];
}
unordered_map<int,LL> ansmu,ansphi;
LL Sphi(int n)
{
    if(n<=maxn) return phi[n];
    if(ansphi[n]) return ansphi[n];
    LL ans=0;
    for(int l=2,r;l<=n;l=r+1) 
        r=n/(n/l),ans+=(r-l+1)*Sphi(n/l);
    return ansphi[n]=n*(n+1ll)/2ll-ans;
}
LL Smu(int n)
{
    if(n<=maxn) return mu[n];
    if(ansmu[n]) return ansmu[n];
    LL ans=1;
    for(int l=2,r;l<=n;l=r+1) 
        r=n/(n/l),ans-=(r-l+1)*Smu(n/l);
    return ansmu[n]=ans;
}

int main()
{
    init();
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        printf("%lld %lld\n",Sphi(n),Smu(n));
    }
    return 0;
}