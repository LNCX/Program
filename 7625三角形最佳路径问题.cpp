#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[105][105]={0},
		f[105][105]={0};
	
	for(int i=1;i<=n;i++)
	for(int j=1;j<=i;j++)
		scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=i;j++)
	{
		if(i==1&&j==1) f[i][j]=a[i][j];
		else f[i][j]=max(f[i-1][j-1],f[i-1][j])+a[i][j];
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		ans=max(ans,f[n][i]);
	cout<<ans<<endl;
	return 0;
}
