#include<iostream>
using namespace std;
long long k[1000]={0,2,3},n;
int main()
{
	cin>>n;
	for(int i=3;i<=n;i++)k[i]=k[i-1]+k[i-2];
	cout<<k[n]<<endl;
	return 0;
}
