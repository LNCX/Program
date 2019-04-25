#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b)
{
    if(b==0) return a;
    else return gcd(b,a%b);
}
ll main()
{
    ll a,b;
    cin>>a>>b;
    ll x=gcd(a,b);
    if(a==a/x*b||b==a/x*b) return puts("0"),0;
    
}