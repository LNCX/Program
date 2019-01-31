#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	if(n<=2) cout<<n<<endl; 
	int a=1,b=2;
	for(int i=3;i<=n;i++)
	{
		int temp=a+b;
		a=b;
		b=temp;
	}
	cout<<b<<endl;
}
