#include<stdio.h>
int main()
{
	float a;
	scanf("%f",&a);
	a=5*(a-32)/9;
	printf("%.4lf",a);
}
