#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,q;
vector<int>v;
ll s1,s2,a[300001];
ll get(ll t)
{
    if(t>0)return -s1*t;
    else return -s2*t;
}
int main()
{
    scanf("%d%d%lld%lld",&n,&q,&s1,&s2);
    
    for(int i=0;i<=n;i++)
    {
        int z;
        scanf("%d",&z);
        v.push_back(z);
    }
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        a[i]=v[i+1]-v[i];
        ans+=get(a[i]);
    }
    while(q--)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        ans-=get(a[x-1]);
        a[x-1]+=z;
        ans+=get(a[x-1]);
        if(y!=n)
        {
            ans-=get(a[y]);
            a[y]-=z;
            ans+=get(a[y]);
        }
        printf("%lld\n",ans);
    }
}