#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
typedef long long LL;
LL phi[N+5],s[N+5],f[N+5];
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
    phi_table(N);
    for(int i=1;i<=N;i++)
        for(int j=i*2;j<=N;j+=i)
            f[j]+=i*phi[j/i];
    s[2]=f[2];
    for(int n=3;n<=N;n++)
        s[n]=s[n-1]+f[n];
    int n;
    while(scanf("%d",&n)&&n)
        printf("%lld\n",s[n]);
    return 0;
}