#include<bits/stdc++.h>
typedef long long LL;
const int mod=1000000007,N=1000,K=50;
int fac[1010],rfac[1010],f[60][1010],ans[1010][60];
int mul(int a,int b)
{return a*(LL)b%mod;}
int C(int n,int k)
{
    return mul(fac[n],mul(rfac[n-k],rfac[k]));
}
int power(int a,int b)
{
    int s=1;
    while(b)
    {
        if(b&1)s=mul(s,a);
        a=mul(a,a);
        b>>=1;
    }
    return s;
}
int main()
{
    int i,j,k,t,n;
    fac[0]=1;
    for(i=1;i<=N;i++)fac[i]=mul(fac[i-1],i);
    rfac[N]=power(fac[N],mod-2);
    for(i=N;i>0;i--)rfac[i-1]=mul(rfac[i],i);
    f[0][0]=1;
    for(i=1;i<=K;i++)
        for(j=i*(i+1)/2;j<=N;j++)
        f[i][j]=(f[i][j-i]+f[i-1][j-i])%mod;
    for(i=1;i<=N;i++)
        for(k=1;k<=K;k++)
        {
            for(j=k*(k+1)/2;j<=i;j++)
                ans[i][k]=(ans[i][k]+mul(C(i-j+k,k),f[k][j]))%mod;
            ans[i][k]=mul(ans[i][k],fac[k]);
        }
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        if(k>K)
            puts("0");
        else
            printf("%d\n",ans[n][k]);
    }
}