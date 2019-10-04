#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
vector<int>a,b;
ll n,g[N],sum,ans;
int main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&g[i]),sum+=g[i];
    ll x=0;    
    for(int i=1;i<=n-2;i++)
    {
        x+=g[i];
        if(3*x==sum)
            a.push_back(i);
    }
    x=0;
    for(int i=n;i>=3;i--)
    {
        x+=g[i];
        if(3*x==sum)
            b.push_back(i);
    }
    reverse(b.begin(),b.end());
    for(auto i:a)
    {
        if(i>=b.back()) break;
        ans+=b.end()-upper_bound(b.begin(),b.end(),i+1);
    }
    printf("%lld\n",ans);
    return 0;
}