#include<iostream>
using namespace std;
int main()
{
	int n,m,a[3005],ans=0x7fffffff;
	cin>>n>>m;
	for(int i=1;i<=n;i++)	cin>>a[i];
	for(int i=0;i<=n-m;i++)
	{
		int count=0;
		for(int j=i+1;j<=m+i;j++)
			count+=a[j];
		if(count<ans) ans=count;
	}
	cout<<ans<<endl;
}
