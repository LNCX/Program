#include<iostream>
#include<cstdio>
using namespace std;
double abs(double a,double b)
{
	double x=a-b;
	if(x<0) x=-x;
	return x;
}
int main()
{
	double x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;
	double sum=abs(x1,x2);
	sum+=abs(y1,y2);
	printf("%.3f",sum);
}

