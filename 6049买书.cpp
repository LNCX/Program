#include<iostream>
using namespace std;
int main()
{
	int n,a[5]={0,10,20,50,100},f[1005]={1};
	cin>>n;
	for(int i=1;i<=4;i++)
	for(int j=a[i];j<=n;j++)
		f[j]+=f[j-a[i]];
	cout<<f[n]<<endl;
}
