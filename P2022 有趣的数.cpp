#include<bits/stdc++.h>
using namespace std;
long long base=1,k,m,n,cnt;
int main()
{
	cin>>k>>m;
	while(base<=k)
	{
		cnt+=k/base-base+1;
        base*=10;
	}
	cnt--;
	base/=10;
	if(cnt>=m||cnt!=m-1&&base==k)
	{
		cout<<0<<endl;
		return 0;
	}
	for(base=k-base,n=k;cnt<m-1;)
	{
		n=n*10;
		base=base*10;
		cnt+=base;
	}
	cout<<max(n-cnt+m-2,k)<<endl;
	return 0;
}