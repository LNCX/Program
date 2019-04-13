#include<iostream>
using namespace std;
int main()
{
	int n,a[16],b[16];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		int max=0;
		for(int j=1;j<i;j++)
		if(a[j]>a[i]&&b[j]>max)
			max=b[j];
		b[i]=max+1;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		if(ans<b[i])
			ans=b[i];
	cout<<ans<<endl;
}
