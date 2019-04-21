#include<cstdio>
#include<iostream>
#define int long long
using namespace std;
int const maxn=1e7+5;
int n,ans=1e16,ans1,ans2,num[maxn];
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a;
		cin>>a;
		if(num[a] && ans>a)
		  ans=a,ans1=num[a],ans2=i;
		else if(!num[a]) num[a]=i;
	}
	for(int i=1;i<maxn;i++)
	{
		int t1=0,t2=0;
		if(i>ans) break;
		for(int j=i;j<maxn;j+=i)
		{
		    if(num[j] && !t1) t1=num[j],t2=j;
		    else if(num[j] && t2*j/i<ans)
		      ans=t2*j/i,ans1=t1,ans2=num[j];
		}
	}
	if(ans1>ans2) swap(ans1,ans2);
	printf("%lld %lld\n",ans1,ans2);
	return 0;
}