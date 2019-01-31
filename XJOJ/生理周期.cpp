#include<bits/stdc++.h>
using namespace std;
int gcd(long a,long b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
int main()
{
	int n=0;
	while(1)
	{
		long long P,E,I,D;		
		scanf("%lld%lld%lld%lld",&P,&E,&I,&D);
		long long m1=P*E/gcd(P,E),m2=I;
		long long ans=m1*m2/gcd(m1,m2);
		for(int i=1;i<=21253;i++)
			if(ans*i>D)
			{
				ans=ans*i;
				break;
			}
		printf("Case %d: the next triple peak occurs in %d days.\n",++n,ans);
	}
	return 0;
}
