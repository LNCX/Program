#include<cmath>
#include<cstdio> 
#include<iostream>
using namespace std;
int main()
{
	long double x=1,n,c;
	cin>>c>>n;
	for(int i=1;i<=10000;i++)
	x=(((n-1)*pow(x,n)+c)/(n*pow(x,n-1)));
	printf("%.30Lf\n\n",x);
	printf("%.30Lf",pow(c,1/n));
}
