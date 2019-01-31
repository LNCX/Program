#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int m,n;
		cin>>m>>n;
		int a[105][105],
			f[105][105];
		for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
		for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
		{
			if(i==1&&j==1) f[i][j]=a[i][j];
			else if(i==1) f[i][j]=a[i][j]+f[i][j-1];
			else if(j==1) f[i][j]=a[i][j]+f[i-1][j];
			else f[i][j]=max(f[i-1][j],f[i][j-1])+a[i][j];
		}
		cout<<f[m][n]<<endl;
	}
}
