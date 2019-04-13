#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[n];
	int m;
	cin>>m;
	int b[m];
	int c[m];
	for(int i=0;i<m;i++) 
	{
		cin>>b[i];
		c[i]=a[0];
	}
	for(int i=0;i<m;i++)
		for(int j=0;i<n;j++)
			if(abs(b[i]-a[j])<c[i]) c[i]=a[j];
	for(int i=0;i<m;i++) cout<<c[i]<<" ";
}
