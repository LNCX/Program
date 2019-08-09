#pragma GCC optimize("O2")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=3e6+5,mod=1e9+7;
ll f[N]={1},ans,h;//考虑f[i][j]=f[i-1][j]+f[i-1][j-i]可以滚动数组
int main()
{
    ll a,b;
    cin>>a>>b; 
    while((h+1)*(h+2)/2<=a+b) h++;
    for(int i=1;i<=h;i++)
        for(int j=a;j>=0;j--)
            if((f[i+j]+=f[j])>=mod) f[i+j]%=mod;
    for(int i=max(h*(h+1)/2-b,1ll*0);i<=a;i++)
        if((ans+=f[i])>=mod) ans%=mod;
    cout<<ans<<endl;
}
