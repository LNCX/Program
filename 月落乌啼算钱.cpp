#include<cmath>
#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	printf("%.2f",(pow((1+sqrt(5))/2.0,n)-
	pow((1-sqrt(5))/2.0,n))/sqrt(5));
	return 0;
}

