#include<bits/stdc++.h>
using namespace std;
const int N=5e4+5;
bool v[N];
int p[N],cnt,mu[N],sum[N];
long long g[N];
void init(int n)
{
    mu[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(!v[i]){p[++cnt]=i;mu[i]=-1;}
        for(int j=1;j<=cnt&&p[j]*i<=n;j++)
        {
            v[p[j]*i]=1;
            if(i%p[j]==0)break;
            else mu[i*p[j]]=-mu[i];
        }
    }
    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]+mu[i];
    for(int i=1;i<=n;i++)
    {
        long long res=0;
        for(int l=1,r;l<=i;l=r+1)
        {
            r=(i/(i/l));
            res+=1ll*(r-l+1)*1ll*(i/l);
        }
        g[i]=res;
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    init(50000);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        long long res=0;
        for(int l=1,r;l<=min(n,m);l=r+1)
        {
            r=min(n/(n/l),m/(m/l));
            res+=(sum[r]-sum[l-1])*1ll*g[n/l]*1ll*g[m/l];
        }
        printf("%lld\n",res);
    }
    return 0;
}