#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll a[3],ans=0;
    cin>>a[0]>>a[1]>>a[2];
    sort(a,a+3);
    if(a[2]/2>(a[0]+a[1])) printf("%lld\n",(a[0]+a[1]));
    else printf("%lld\n",(a[0]+a[1]+a[2])/3);
    return 0;
}