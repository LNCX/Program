#include<bits/stdc++.h>
using namespace std;
int ans=0,a[105][105],f[105][105],n,m;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
		scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		if(a[i][j])
		{
			int mid=min(f[i-1][j],f[i][j-1]);
			mid=min(mid,f[i-1][j-1]);
			f[i][j]=mid+1;
			ans=max(f[i][j],ans);	
		}	
	}
	cout<<ans<<endl;	
}

