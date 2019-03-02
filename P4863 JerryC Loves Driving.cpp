#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b;
	long long ans=0,r,s,t;
	cin>>a>>b;
	for(int i=1;i<=b;i++)
	{
		r=a/i-1;
		s=(a-r*i-i)*(r+1);
		r=(r+1)*r/2*i;
		t=s+r;
		r=(b+1)/i-1;
		s=(b+1-r*i-i)*(r+1);
		r=(r+1)*r/2*i;
		if(i&1)
			ans-=s+r-t;
		else
			ans+=s+r-t;
	}
	cout<<ans<<endl;
	return 0;
}