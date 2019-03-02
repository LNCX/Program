#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main()
{
    int n;
    cin>>n;
    LL l1=0,r1=0,ans=1;
    for(int i=1;i<=n;i++)
    {
        LL l2,r2;
        scanf("%lld%lld",&l2,&r2);
        if(l1<r1)
        {
            if(r1<=l2)
                l1=r1,ans++;
            else l1=l2;
        }
        else if(l1>r1)
        {
            if(l1<=r2) r1=l1,ans++;
            else r1=r2;
        }
        if(min(l2,r2)>max(l1,r1))
            ans+=min(l2,r2)-max(l1,r1);
        l1=l2,r1=r2;
    }
    cout<<ans<<endl;
    return 0;
}