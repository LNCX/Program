#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
long long a[maxn],ans,n,x=0x7fffffffff;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for(int i=n;i>0;i--)
    {
        x=min(x-1,a[i]);
        if(x>0) ans+=x;
    }
    cout<<ans<<endl;
    return 0;
}