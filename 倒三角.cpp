#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	long long int a=0;
	cin>>a;
	long long int b=a;
	while(a!=0)
	{
		for(int i=b-a;i>=1;i--)
			cout<<" ";
		for(int k=2*a-1;k>=1;k--)
			cout<<"#";
		cout<<endl;
		a--;
	}

}
