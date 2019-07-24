#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+5;
struct seg
{
    ll x,y,z;
    seg operator+(const seg a) const
    {
        seg c;c.x=a.x+x,c.y=a.y+y,c.z=a.z+z;
        return c;
    }
    seg(){x=y=z=0;}
};
ll tag[N<<2];
seg sum[N<<2];
ll cal(ll x){return x*(x+1)*(2*x+1)/6;}
void update(ll k,ll l,ll r,ll w)
{
    sum[k].x+=(r-l+1)*w;
    sum[k].y+=(r+l)*(r-l+1)*w/2;
    sum[k].z+=(cal(r)-cal(l-1))*w;
    tag[k]+=w;
}
void pushdown(ll k,ll l,ll r)
{
    if(!tag[k]) return;
    ll mid=(l+r)>>1;
    update(k<<1,l,mid,tag[k]);
    update(k<<1|1,mid+1,r,tag[k]);
    tag[k]=0;
}
void modify(ll k,ll l,ll r,ll x,ll y,ll w)
{
    if(r<x||l>y) return ;
    if(x<=l&&r<=y)
    {
        update(k,l,r,w);
        return;
    }
    pushdown(k,l,r);
    ll mid=(l+r)>>1;
    modify(k<<1,l,mid,x,y,w);
    modify(k<<1|1,mid+1,r,x,y,w);
    sum[k]=sum[k<<1]+sum[k<<1|1];
}
seg query(ll k,ll l,ll r,ll x,ll y)
{
    if(x<=l&&r<=y) return sum[k];
    pushdown(k,l,r);
    seg res;
    ll mid=(l+r)>>1;
    if(x<=mid) res=res+query(k<<1,l,mid,x,y);
    if(y >mid) res=res+query(k<<1|1,mid+1,r,x,y);
    return res;
}
ll gcd(ll a,ll b){return !b?a:gcd(b,a%b);}
signed main()
{
    ll n,m;
    scanf("%lld%lld",&n,&m);
    while(m--)
    {
        char s[5];
        ll w,l,r;
        scanf("%s%lld%lld",s,&l,&r);r--;
        if(*s=='C')
        {
            scanf("%lld",&w);
            modify(1,1,n,l,r,w);
        }
        else
        {
            seg k=query(1,1,n,l,r);
            ll a=(r+1-l-l*r)*k.x+(l+r)*k.y-k.z, b=(r-l+2)*(r-l+1)/2;
            printf("%lld/%lld\n",a/gcd(a,b),b/gcd(a,b));
        }
    }
    return 0;
}