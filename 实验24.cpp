#include<bits/stdc++.h>
using namespace std;
int f[15]={0,2,3,4,6};
int main()
{
	int n;
	cin>>n;
	for(int i=3;i<=n;i++)
		f[i]=f[i-1]+f[i-3];
	cout<<f[n]<<endl;
	return 0;
}
