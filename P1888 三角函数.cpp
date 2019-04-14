#include<cstdio>
#include<iostream>
using namespace std;
long long gcd(long long a,long long b)
{
    return b==0?a:gcd(b,a%b);
}
int main()
{
	long long a[3],q,w,max=0,min=2000000000;
	scanf("%lld%lld%lld",&a[0],&a[1],&a[2]);
	for(int i=0;i<3;i++)
	{
		if(a[i]<min) min=a[i];
		if(a[i]>max) max=a[i]; 
	}
	q=max/gcd(max,min);
	w=min/gcd(max,min);
	cout<<w<<"/"<<q<<endl;
    return 0;
}

