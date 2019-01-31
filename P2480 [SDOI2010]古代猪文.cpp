#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int mod=999911658;
LL n,g,num[50010],a[5],b[5]={0,2,3,4679,35617},val;
LL power(LL a,LL b,LL p)
{
    a%=p;
    LL ans=1;
    while(b)
    {
        if(b&1) ans=ans*a%p;
        a=a*a%p;
        b>>=1;
    }
    return ans;
}
LL C(LL n,LL m,LL p)
{
    if(n<m) return 0;
    return num[n]*power(num[m],p-2,p)%p*power(num[n-m],p-2,p)%p;
}
LL Lucas(LL n,LL m,LL p)
{
    if(n<m) return 0;if(!n) return 1;
    return Lucas(n/p,m/p,p)*C(n%p,m%p,p)%p;
}
int main()
{
    scanf("%lld%lld",&n,&g);
    if(g%(mod+1)==0)
    {
        printf("0\n");
        return 0;
    }    
    for(LL k=1;k<=4;k++)
    {
        num[0]=1;
        for(LL i=1;i<=b[k];i++)
        num[i]=num[i-1]*i%b[k];
        for(LL i=1;i*i<=n;i++)
            if(n%i==0)
            {
                a[k]=(a[k]+Lucas(n,i,b[k]))%b[k];
                if(i*i!=n) a[k]=(a[k]+Lucas(n,n/i,b[k]))%b[k];
            }
    }
    for(LL i=1;i<=4;i++)
        val=(val+a[i]*(mod/b[i])%mod*power(mod/b[i],b[i]-2,b[i]))%mod;
    printf("%lld\n",power(g,val,mod+1));
    return 0;
}