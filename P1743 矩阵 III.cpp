#include<bits/stdc++.h>
using namespace std;
double C(long long n,long long m)
{
	double res=1;
	for(int i=0;i<m;i++)
		res=res*(n-i)/i;
	return res;
}
int main()
{
	long long n,m;
	scanf("%lld%lld",&n,&m);
	cout<<C(n+m,m)<<endl;
}
