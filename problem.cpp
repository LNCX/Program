#include<bits/stdc++.h>
using namespace std;
int f[1005][1005];
int main()
{
	int n,x=9;
	cin>>n;
	f[1][0]=9,f[1][1]=1;
	for(int i=2;i<=n;i++)
	{
		if(i==n)x--;
		f[i][0]=(f[i-1][1]+f[i-1][0]*x)%12345;
		f[i][1]=(f[i-1][0]+f[i-1][1]*x)%12345;
	}
	cout<<f[n][0]<<endl;
} 
