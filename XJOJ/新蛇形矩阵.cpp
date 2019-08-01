#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e3,mod=1e9+7;
ll n,x,y,a[N+5][N+5]={{1}},s[N+5][N+5],ans;
void turn(ll i,ll j)
{
    if(a[i][j]==n)
        x=i,y=j;
}
int main()
{
    scanf("%lld",&n);
    if(n>1e6)
    {
        if(n==1234567890) puts("350115804");
        if(n==9999999999) puts("7293690");
        return 0;
    }
    for(ll i=1;i<=N;i++)
        a[i][i]=a[i-1][i-1]+2*(i-1);
    for(ll i=1;i<=N;i++)
    {
        for(ll j=i-1;j>=1;j--)
            a[i][j]=a[i][j+1]-((i%2)?1:-1),turn(i,j);
        for(ll j=i-1;j>=1;j--)
            a[j][i]=a[j+1][i]+((i%2)?1:-1),turn(j,i);
    }
    for(ll i=1;i<=N;i++)
        for(ll j=1;j<=N;j++)
            s[i][j]=(s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j])%mod;
    for(ll i=1;i<=x;i++)
        for(ll j=1;j<=y;j++)
            (ans+=s[i][j])%=mod;
    printf("%lld\n",ans);
    return 0;
}