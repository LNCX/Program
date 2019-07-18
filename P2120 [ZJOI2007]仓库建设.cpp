#include<bits/stdc++.h>
using namespace std;
const int maxn=1000005;
int n,m,x[maxn],q[maxn],c[maxn];
long long f[maxn],sum[maxn],s[maxn];
double calc(int j,int k)
{return (f[k]-f[j]+sum[k]-sum[j])*1.0/(s[k]-s[j]);}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%lld%d",&x[i],&s[i],&c[i]);
        sum[i]=sum[i-1]+x[i]*s[i];s[i]+=s[i-1];
    }
    for(int i=1,l=0,r=0;i<=n;i++)
    {
        while(l<r&&x[i]>calc(q[l],q[l+1]))l++;
        f[i]=f[q[l]]+c[i]-sum[i]+sum[q[l]]+x[i]*(s[i]-s[q[l]]);
        while(l<r&&calc(q[r-1],q[r])>calc(q[r],i))r--;
        q[++r]=i;
    }
    printf("%lld\n",f[n]);
}