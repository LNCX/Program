#include<iostream>
using namespace std;
int main()
{
	long long b,p,k;
	cin>>b>>p>>k;
	long long n=b;
	for(int i=1;i<=p;i++)
	{
		b*=b;
		b%=k;
	}
	printf("%d^%d mod %d=%d\n",n,p,k,b);
}
