#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,k,r=9e18;
void check(ll i)
{
	ll x=(a+i-1)/i*i,t=x/i*(x+(b-a));
	if(r>=t)r=t,k=x-a;
};
int main()
{
	scanf("%lld %lld",&a,&b);
	if(a>b)swap(a,b);
	for(int i=1;i*i<=b-a;i++)
        if((b-a)%i==0)
            check(i),check((b-a)/i);
    printf("%lld\n",k);
}