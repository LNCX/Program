#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a,b,c;
    scanf("%lld%lld%lld",&a,&b,&c);
    long long ans=2*c+2*min(a,b);
    if(a-min(a,b)>0||b-min(a,b)>0) ans++;
    cout<<ans<<endl;
    return 0;
}