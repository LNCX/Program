#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
int main()
{
	int n;
	cin>>n;
	for(int j=1;j<=n;j++)
	{
		int x,a0,a1,b0,b1;
		scanf("%d%d%d%d",&a0,&a1,&b0,&b1);
		int ans=0;
		if(b1%b0!=0)
		{
			cout<<0<<endl;
			continue;
		}
		for(int i=1;i<sqrt(b0);i++)
			if(b0%i==0)
			{
				x=b1/b0*i;
				if(gcd(x,b0)==i&&gcd(x,a0)==a1) ans++;
				x=b1/b0*(b0/i);
				if(gcd(x,b0)==b0/i&&gcd(x,a0)==a1) ans++;
			}
		int k=sqrt(b0);
		if(k*k==b0&&b0%k==0)
		{
			x=b1/b0*k;
			if(gcd(x,b0)==k&&gcd(x,a0)==a1) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
