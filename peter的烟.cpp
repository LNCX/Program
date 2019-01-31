#include<iostream>
using namespace std;
int main()
{
	int ans=0,mid=0,n,k;
	cin>>n>>k;
	while(n)
	{
		ans+=n;
		mid+=n;
		n=mid/k;
		mid%=k;
	}
	cout<<ans<<endl; 
}
