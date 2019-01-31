#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,count=0;
	cin>>n;
	if(n==1)
	{
		cout<<0<<endl;
		return 0;
	}
	while(n!=1)
	{
		if(n%2==0)	n/=2;
		else n=3*n+1;
		count++;
	}
	cout<<count<<endl;
}

