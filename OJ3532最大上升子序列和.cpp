#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[1005],b[1005];
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		int max=0;
		for(int j=1;j<i;j++)
			if(a[j]<a[i]&&b[j]>max)
				max=b[j];
		b[i]=max+a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	if(b[i]>ans)
		ans=b[i];
	cout<<ans<<endl;
}
