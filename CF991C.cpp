#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,ans;
int check(LL x)
{
    LL tmp=n,tot=0;
    while(tmp)
    {
        if(tmp>x)
        {
            tot+=x;
            tmp-=x;
            tmp-=tmp/10;
        } 
        else
        {
            tot+=tmp;
            tmp=0;
        }
    }
    if(tot>=n/2+(n%2))
        return 1;
    return 0;
}
int main()
{
    cin>>n;
    LL l=1,r=n;
    while(l<=r)
    {
        LL mid=(l+r)>>1;
        if(check(mid)) r=mid-1,ans=mid;
        else l=mid+1;
    }
    cout<<ans<<endl;
    return 0;
}