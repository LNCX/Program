#include<cstdio>
#include<cmath>
using namespace std;
double f(double x,double n)
{
	if(n==1) return (sqrt(1+x));
	else return(sqrt(n+f(x,n-1)));
}
int main()
{
	double n,x;
	scanf("%lf%lf",&x,&n);
	printf("%.2f",f(x,n));
}
