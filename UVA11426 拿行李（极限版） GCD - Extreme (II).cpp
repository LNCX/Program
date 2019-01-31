#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
typedef long long LL;
LL phi[maxn+5],s[maxn+5],f[maxn+5];
void phi_table(int n)
{
    phi[1]=1;
    for(int i=2;i<=n;i++) if(!phi[i])
        for(int j=i;j<=n;j+=i)
        {
            if(!phi[j]) phi[j]=j;
            phi[j]=phi[j]/i*(i-1);
        }
}
int main()
{
    phi_table(maxn);
    for(int i=1;i<=maxn;i++)
        for(int j=i*2;j<=maxn;j+=i)
            f[j]+=i*phi[j/i];
    s[2]=f[2];
    for(int n=3;n<=maxn;n++)
        s[n]=s[n-1]+f[n];
    int n;
    while(scanf("%d",&n)&&n)
        printf("%lld\n",s[n]);
    return 0;
}