#include<iostream>
#include<cmath>
#include <iomanip>
using namespace std;
int main()
{
	double a,b,c;
	cin>>a>>b>>c;
	double p=(a+b+c)/2;
	double sum=sqrt(p*(p-a)*(p-b)*(p-c)) ;
	cout.setf(ios::fixed);
	cout<<fixed<<setprecision(4)<<sum<<endl; 
} 
