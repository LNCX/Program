#include<iostream>
using namespace std;
int main()
{
	while(1)
	{
	int a;
	cin>>a;
	int b=a/100;
	int c=(a-100*b)/10;
	int d=a-(100*b)-10*c;
	cout<<d<<c<<b<<endl;
    }
}
