#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
set<ll>que;
void f(ll n,ll i)
{
	ll d=n/i;
	ll ans=d+d*(d-1)*i/2;
	que.insert(ans);
}
int main()
{
	ll n;
	cin>>n;
	if(n%2==0) que.insert(n/2+2);
	que.insert(1);
	que.insert((n*(n+1))/2);
	for(ll i=2;i*i<=n;i++)
	{
		if(n%i!=0)	continue;
		f(n,i);
		f(n,n/i);
	}
	set<ll>::iterator it = que.begin();
	for(;it!=que.end();it++)
	cout<<*it<<" ";
}
