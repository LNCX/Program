#include <cstdio>
long long a[1000001];
int main()
{
    long long ans=0,n=0;
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
    {
    	scanf("%lld",&a[i]);
    	ans+=a[i];
	}
    if(!(ans&1)) printf("Bob");
	else printf("Alice");
}
