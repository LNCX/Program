#include<iostream>
using namespace std;
long long f(int n)
{
	if(n==1) return 0;
	else if(n==3||n==2) return 1;
	else return f(n-1)+f(n-2); 
}
int main()
{
	int n;
	cin>>n;
	cout<<f(n)<<endl;
}
