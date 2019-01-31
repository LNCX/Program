#include<bits/stdc++.h>
using namespace std;
int main()
{
	int sum=0,ans=0,a[100005],n,max;
	cin>>n>>max;
	for(int i=1;i<=n;i++)	scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		if(sum+a[i]>max)
		{
			sum=0;
			ans++;
		}
		sum+=a[i];
	}
	cout<<ans+1<<endl;
}
