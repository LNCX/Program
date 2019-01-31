#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
int main()
{
	int t;
	ull n,s,sum,x;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld %lld",&n,&s);
		x=n-1;
		sum=(n*(n+1))/2;
		if(s==sum)
		{
			printf("%d\n",0);
			continue;
		}
		while(sum>=s&&x)
		{
			sum-=x;
			x--;
		}
		printf("%lld\n",n-(x+1));
	}
	return 0;
}

