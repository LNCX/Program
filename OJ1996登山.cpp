#include<iostream>
using namespace	std;
int main()
{
	int n,a[1005],b[1005],c[1005];
	cin>>n;
	for(int i=1;i<=n;i++)	scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		int max=0;
		for(int j=1;j<i;j++)
			if(a[j]<a[i]&&b[j]>max)
				max=b[j];
		b[i]=max+1;
	}
	for(int i=n;i>=1;i--)
	{
		int max=0;
		for(int j=n;j>i;j--)
			if(a[j]<a[i]&&c[j]>max)
				max=c[j];
		c[i]=max+1;
	}
	int ans=0,loc;
	for(int i=1;i<=n;i++)
		if(b[i]+c[i]>ans)
			ans=b[i]+c[i]-1;
	cout<<ans<<endl; 
}
