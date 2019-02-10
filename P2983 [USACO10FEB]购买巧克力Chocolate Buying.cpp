#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=1e5+5;
LL n,b,ans;
struct node
{
    LL p,c;
    bool operator<(const node&x) const
    {
        return p<x.p;
    }
}a[maxn];
int main()
{
    scanf("%lld%lld",&n,&b);
    for(int i=1;i<=n;i++)
        scanf("%lld%lld",&a[i].p,&a[i].c);
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    {
        if(b/a[i].p<a[i].c)
        {
            ans+=b/a[i].p;
            break;
        }
        ans+=a[i].c;
        b-=a[i].c*a[i].p;
    }
    cout<<ans<<endl;
    return 0;
}