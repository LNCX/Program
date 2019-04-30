#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=2000000;
int p[maxn+10],N;
bool phiv[maxn+10],muv[maxn+10],v[maxn+10];
LL mu[maxn+10],phi[maxn+10],ansmu[maxn],ansphi[maxn];
inline void init()
{
    v[1]=mu[1]=phi[1]=1;
    int tot=0;
    for(int i=2;i<=maxn;i++)
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
LL Sphi(int n)
{
    if(n<=maxn) return phi[n];
    int x=N/n;
    if(phiv[x]) return ansphi[x];
    phiv[x]=true;
    LL ans=0;
    for(int l=2,r;l<=n;l=r+1) 
        r=n/(n/l),ans+=(r-l+1)*Sphi(n/l);
    return ansphi[x]=n*(n+1ll)/2ll-ans;
}
LL Smu(int n)
{
    if(n<=maxn) return mu[n];
    int x=N/n;
    if(muv[x]) return ansmu[x];
    muv[x]=true;
    LL ans=1;
    for(int l=2,r;l<=n;l=r+1) 
        r=n/(n/l),ans-=(r-l+1)*Smu(n/l);
    return ansmu[x]=ans;
}
int main()
{
    init();
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&N);
        fill(phiv,phiv+maxn+1,false);
        fill(muv,muv+maxn+1,false);
        printf("%lld %lld\n",Sphi(N),Smu(N));
    }
    return 0;
}