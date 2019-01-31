#include<bits/stdc++.h>
using namespace std;
int g[205][205],f[205][205],used[205][205];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<n;i++)
	for(int j=i+1;j<=n;j++)
	{
		scanf("%d",&g[i][j]);
		f[i][j]=g[i][j];
		used[i][j]=true;
	}
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	if(f[i][j]>f[i][k]+f[k][j])
	if(used[i][j]&&used[i][k]&&used[k][j])
		f[i][j]=f[i][k]+f[k][j];
	cout<<f[1][n]<<endl;	
}
