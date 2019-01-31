#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>

using namespace std ;

int jia(int a,int b)
{
	return a*b+b*a;
}

int jian(int a,int b)
{
	return a+b+a*b;
}

int cheng(int a,int b)
{
	return b*b+a*a;
}

int chu(int a,int b)
{
	return b-a+b*a;
}

int a=0,b,n;
char c;

int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		cin>>c>>b;
		switch(c)
		{
			case '+':
				printf("%d\n",a=(jia(a,b))%12345);
				break;
			case '-':
				printf("%d\n",a=(jian(a,b))%12345);
				break;
			case '*':
				printf("%d\n",a=(cheng(a,b))%12345);
				break;
			case '/':
				printf("%d\n",a=(chu(a,b))%12345);
				break;
		}
	}
	return 0;
}
