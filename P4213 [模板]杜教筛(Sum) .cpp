#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2000000;
int p[N+10],N;
bool phiv[N+10],muv[N+10],v[N+10];
LL mu[N+10],phi[N+10],ansmu[N],ansphi[N];
inline void init()
{
    v[1]=mu[1]=phi[1]=1;
    int tot=0;
    for(int i=2;i<=N;i++)
    {
        if (!v[i]) p[++tot]=i,mu[i]=-1,phi[i]=i-1;
        for(int j=1;j<=tot&&i*p[j]<=N;++j)
        {
            v[i*p[j]]=1;
            if(i%p[j]) mu[i*p[j]]=-mu[i],phi[i*p[j]]=phi[i]*phi[p[j]];
            else {mu[i*p[j]]=0,phi[i*p[j]]=phi[i]*p[j];break;}
        }
    }
    for(int i=1;i<=N;++i)
        mu[i]+=mu[i-1],phi[i]+=phi[i-1];
}
LL Sphi(int n)
{
    if(n<=N) return phi[n];
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
    if(n<=N) return mu[n];
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
        fill(phiv,phiv+N+1,false);
        fill(muv,muv+N+1,false);
        printf("%lld %lld\n",Sphi(N),Smu(N));
    }
    return 0;
}