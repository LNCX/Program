#include<iostream>
using namespace std;
int a[5]={0,1,2,9};
int main()
{
	int n,k;
	long long sum=1;
	cin>>n>>k;
	for(int i=1;i<=k;i++)
		sum+=a(i)*c(n,i);
	cout<<sum<<endl;
}
