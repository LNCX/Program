#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
typedef long long ll;
ll cnt,ans,t[N];
set<ll>s;
map<ll,ll>id;
map< ll,vector<ll> >mp;
void fix(ll x){while(x<N)t[x]++,x+=(x&(-x));}
ll ask(ll x){ll res=0;while(x>0)res+=t[x],x-=(x&(-x));return res;}
int main()
{
    ll n;
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++)
    {
        ll x,y;
        scanf("%lld%lld",&x,&y);
        mp[-y].push_back(x);
        s.insert(x);
    }
    for(auto x:s) id[x]=++cnt;
    for(auto it:mp)
    {
        #define d mp[y]
        ll y=it.first,lst=0;
        sort(d.begin(),d.end());
        for(auto x:d)
            if(s.count(x))
                fix(id[x]),s.erase(x);
        for(auto x:d)
        {
            ll l=ask(id[x]),r=ask(N-1);
            ans+=(l-lst)*(r-l+1);
            lst=l;
        }
    }
    printf("%lld\n",ans);
    return 0;
}