#include<bits/stdc++.h>
using namespace std;
const int N=100010,mod=1000000007;
int m,f[N],fac[7],fl;
inline int power(int a,int b)
{
    a%=mod;
    int res=1;
    while(b)
    {
        if(b&1) res=1ll*res*a%mod;
        a=1ll*a*a%mod;
        b>>=1;
    }
    return res;
}
int dfs(int dep,int pro,int sgn,int up)
{    
    if(dep>fl) return up/pro*sgn;
    else return dfs(dep+1,pro,sgn,up)+dfs(dep+1,pro*fac[dep],-sgn,up);
}
int cnt(int x,int y)
{
    fl=0;
    for(int i=2;i*i<=x;i++)
        if(x%i==0)
        {
            fac[++fl]=i;
            while(x%i==0) x/=i;
        }
    if(x>1) fac[++fl]=x;
    return dfs(1,1,1,y);
}
int main()
{
    cin>>m;
    int inv=power(m,mod-2);
    f[1]=0;
    for(int i=1;i<=m;i++)
    {
        if(i!=1)
        {    
            f[i]=1ll*f[i]*inv%mod;
            f[i]=(f[i]+1)%mod;
            f[i]=1ll*f[i]*power((1-1ll*(m/i)*inv%mod+mod)%mod,mod-2)%mod;
        }
        for(int j=2;j<=m/i;j++)
            f[i*j]=(f[i*j]+1ll*f[i]*cnt(j,m/i))%mod;
    }
    int ans=0;
    for(int i=1;i<=m;i++) ans=(ans+f[i]+1)%mod;    
    ans=1ll*ans*inv%mod;
    printf("%d\n",ans);
}