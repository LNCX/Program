#include<bits/stdc++.h>
using namespace std;
int a[1005][1005],b[1005],c[1005];
int main()
{
	int ans=0,n;
	cin>>n;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
		scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		b[i]+=a[i][j];
		c[j]+=a[i][j];
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
		if(a[i][j]==0)
			ans=max(b[i]+c[j],ans);		
	cout<<ans<<endl;
}
