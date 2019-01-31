#include<iostream>
using namespace std;
int main()
{
	int i=1;
	double mid=2,sum=2,n;
	cin>>n;
	while(sum<n)
	{
		mid*=0.98;
		sum+=mid;
		i++;
	}
	cout<<i<<endl;
} 
