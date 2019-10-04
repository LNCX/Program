#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,mod=1e9+7;
int f[N]={1},sum[N];
int main()
{
    int t,k,n=1e5;
    scanf("%d%d",&t,&k);
    for(int i=1;i<=n;i++)
    {
        if(i-1>=0) (f[i]+=f[i-1])%=mod;
        if(i-k>=0) (f[i]+=f[i-k])%=mod;
    }    
    for(int i=1;i<=n;i++)
        (sum[i]=sum[i-1]+f[i])%=mod;
    while(t--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        printf("%d\n",((sum[b]-sum[a-1])%mod+mod)%mod);
    }
    return 0;
}