#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const ll N=2e5+5,mod=1e9+7;
ll f[N][3],cnt[3];
int main()
{
    int n,l,r;
    scanf("%d%d%d",&n,&l,&r);
    for(int i=0;i<3;i++)
		f[1][i]=cnt[i]=(r-i+3)/3-(l-i+2)/3;
    for(int i=2;i<=n;i++)
    {
        f[i][0]=(f[i-1][0]*cnt[0]%mod+f[i-1][1]*cnt[2]%mod+f[i-1][2]*cnt[1]%mod)%mod;
        f[i][1]=(f[i-1][0]*cnt[1]%mod+f[i-1][1]*cnt[0]%mod+f[i-1][2]*cnt[2]%mod)%mod;
        f[i][2]=(f[i-1][0]*cnt[2]%mod+f[i-1][1]*cnt[1]%mod+f[i-1][2]*cnt[0]%mod)%mod;
    }        
    cout<<f[n][0]%mod<<endl;
    return 0;
}