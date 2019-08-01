#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
    cin>>t;
    while(t--)
    {
        long long a,b,c;
        scanf("%lld%lld%lld",&a,&b,&c);
        printf("%lld\n",(a+b+c)>>1);
    }
	return 0;
}