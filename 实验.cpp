#include<bits/stdc++.h>
using namespace std;
long long a,p,n,ans=1;
int main()
{
	scanf("%d%d%d",&a,&n,&p);
	a%=p;
	while(n)
	{
		if(n%2==1)
			ans=(ans*a)%p;
		n/=2;
		a=(a*a)%p;
	}
	printf("%lld",ans%p);
}
