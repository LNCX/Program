#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=55;
ll p[N];
void insert(ll x)
{
    for(int i=50;i>=0;i--)
    {
        if(!(x>>i)) continue;
        if(!p[i]) {p[i]=x;break;}
        else x^=p[i];
    }
}
int main()
{
    int n ;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        ll x;
        scanf("%lld",&x);
        insert(x);
    }
    ll ans=0;
    for(int i=50;i>=0;i--)
        if((ans^p[i])>ans)
            ans^=p[i];
    cout<<ans<<endl;
    return 0;
}