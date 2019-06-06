#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n,m;
    cin>>n>>m;
    ll x=n/m,y=(n-(x*m)),z=n-m+1;    
    //cerr<<x<<" "<<y<<" "<<z<<endl;
    ll ans1=x*(x-1)/2*m+y*x;
    ll ans2=z*(z-1)/2;
    cout<<ans1<<" "<<ans2<<endl;
    return 0;
}