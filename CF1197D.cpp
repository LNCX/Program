#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=3e5+5,inf=1e18;
ll a[N],f[N],mx[N],ans;
int main()
{
    ll n,m,k;
    scanf("%lld%lld%lld",&n,&m,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        a[i]+=a[i-1];
        f[i]=a[i]-k*(i/m);
    }
    for(int i=1;i<m;i++) mx[i]=inf;
    for(int i=1;i<=n;i++)
    {
        ll x=-inf;
        for(int j=0;j<m;j++)
           x=max(x,f[i]-mx[j]-k*(ll)ceil((double)(i%m-j)/m)); 
        mx[i%m]=min(f[i],mx[i%m]);
        ans=max(ans,x);
    }
    cout<<ans<<endl;
    return 0;
}