//#pragma GCC optimize("O2")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<ll,ll>m;
inline ll read()
{
    ll x=0;
    char c=getchar();
    while(!isdigit(c)) c=getchar();
    while(isdigit(c))
    {
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x;
}
struct node
{
    ll x,y;
    bool operator<(const node&s) const
    {
        return x<s.x;
    }
};
vector<node>a;
signed main()
{
    ll n=read();
    for(ll i=1;i<=n;i++)
    {
        ll x=read();
        m[x]++;
    }
    for(auto it=m.begin();it!=m.end();it++)
        a.push_back((node){it->first,it->second});
    sort(a.begin(),a.end());
    for(ll i=0;i<a.size();i++)
        printf("%lld %lld\n",a[i].x,a[i].y);
    return 0;
}