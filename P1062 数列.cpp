#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long cnt=0,n,k,ans=0;
	cin>>k>>n;
	while(n)
	{
		ans+=(n%2)*pow(k,cnt);
		n/=2;
		cnt++;
	}
	cout<<ans<<endl;
}
