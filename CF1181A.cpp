#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x,y,z,ans;
int main()
{
    cin>>x>>y>>z;
    ans+=x/z,x=x%z;
    ans+=y/z,y=y%z;
    if(x+y-z<0)
    {
        printf("%lld %d\n",ans,0);
        return 0;
    }
    if(x<y) swap(x,y);
    printf("%lld %lld\n",ans+1,z-x);
    return 0;
}