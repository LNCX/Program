#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n;
    cin>>n;
    ll l=1,r=2e9;
    while(l<r)
    {
        ll x=(l+r)>>1;
        if((x*log10(1.0*x))+1<n) l=x+1;
        else r=x;
    }
    cout<<l<<endl;
    return 0;
}