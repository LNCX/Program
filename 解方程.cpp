#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	float a,b,c;
	cin>>a>>b>>c;
	float x=(b*b-4*a*c);
	if(x==0) printf("x1=x2=%.5f",-b/(2*a));
	else if(x>0)
	{
		float x1=(-b+sqrt(x))/(2*a);
		float x2=(-b-sqrt(x))/(2*a);
		if(x1<x2)
		{
			float t=x1;
			x1=x2;
			x2=t;
		}
		printf("x1=%.5f;x2=%.5f",x1,x2);
	}
	else
	{
		float t=-b/(2*a),f=sqrt(-x)/2/a;
		if(t==0) t=-t;
		float x1=f,x2=-f;
		if(x1<x2)
		{
			float t=x1;
			x1=x2;
			x2=t;
		}
		if(x1>0&&x2<0)
		printf("x1=%.5f%+.5fi;x2=%.5f%.5fi",t,x1,t,x2);
		else if(x1>0&&x2>0)
		printf("x1=%.5f%+.5fi;x2=%.5f+%.5fi",t,x1,t,x2);
		else
		printf("x1=%.5f%.5fi;x2=%.5f%.5fi",t,x1,t,x2);
	}
} 
