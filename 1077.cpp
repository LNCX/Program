#include<bits/stdc++.h>
using namespace std;
int a[101];
int f(int n,int m,int t)
{
	int i;
	if (n<m) return 0;
	for (i=m;i<=n/2;i++)
	{
		a[t+1]=i;
		f(n-i,i,t+1);
		a[t+1]=0;
	}
	if (t)
	{
		for (i=1;i<=t;i++)
		cout<<a[i]<<"+";
		cout<<n<<endl;
	}
	return 0;
}
int main()
{
	int n;
	memset(a,0,sizeof(a));
	cin>>n;
	f(n,1,0);
	return 0;
}
