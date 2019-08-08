#include<cstdio>
using namespace std;
typedef long long ll;
const ll N=1e3+5;
ll x1[N],x2[N],y1[N],y2[N],n,ans;
void solve(ll a,ll d,ll w,ll s,ll t)
{
    if(a>d||w<s)return;
    while(t>0&&(a>=x2[t]||d<=x1[t]||w<=y2[t]||s>=y1[t]))
        t--;
    if(!t){ans+=(d-a)*(w-s);return;}
    if(a<x1[t]) solve(a,x1[t],w,s,t-1),a=x1[t];
    if(d>x2[t]) solve(x2[t],d,w,s,t-1),d=x2[t];
    if(w>y1[t]) solve(a,d,w,y1[t],t-1),w=y1[t];
    if(s<y2[t]) solve(a,d,y2[t],s,t-1),s=y2[t];
}
int main()
{
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++)
        scanf("%lld%lld%lld%lld",&x1[i],&y1[i],&x2[i],&y2[i]);
    for(ll i=1;i<=n;i++)
        solve(x1[i],x2[i],y1[i],y2[i],i-1);
    printf("%lld\n",ans);
    return 0;
}