#include<cstdio>
#include<iostream>
using namespace std;
int n,ans,a[10]={6,2,5,5,4,5,6,3,7,6};
int match(int m)
{
	int res=0;
	if(m==0) return 6;
	while(m!=0)
	{
		res+=a[m%10];
		m/=10;
	}
	return res;
}
int main()
{
	cin>>n;
	for(int i=0;i<=1000;i++)
	for(int j=0;j<=1000;j++)
		if(match(i)+match(j)+match(i+j)+4==n)
			ans++;
	cout<<ans<<endl; 
}
