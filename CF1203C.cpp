#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=4e5+5;
ll a[N],ans;
ll gcd(ll a,ll b)
{   
    if(b==0) return a;
    else return gcd(b,a%b);
}
void divide(ll x)
{
    for(ll i=1;i*i<=x;i++)
    {
        if(x%i==0)
        {
            ans++;
            if(i*i!=x) ans++;        
        }
    }
}
int main() 
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    ll x=a[1];
    for(int i=2;i<=n;i++)
        x=gcd(x,a[i]);
    divide(x);
    cout<<ans<<endl;
    return 0;

}