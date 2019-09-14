#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
    scanf("%d",&t);
    while(t--)
    {
        long long n;
		scanf("%lld", &n);
		printf("%lld\n",n==4||n==10?n+1:n-1);
	}
	return 0;
}