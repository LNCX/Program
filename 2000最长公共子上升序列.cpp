#include<cstdio>
#include<iostream>
using namespace std;
int m,n,a[505],b[505],
	c[505][505],f[505][505];
int main()
{
	cin>>m>>n;
	for(int i=1;i<=m;i++)	scanf("%d",&a[i]);
	for(int j=1;j<=n;j++)	scanf("%d",&b[j]);
	for(int i=1;i<=m;i++)
	for(int j=1;j<=n;j++)
	{
		if(a[i]!=b[i])	f[i][j]=f[i-1][j];
		else
		{
			int max=0;
			for(int k=1;k<j;k++)
				if(b[k]<b[j]&&f[i-1][k]>max)
					max=f[i-1][k];
			f[i][j]=max+1;
		}
	}
	cout<<f[m][n]<<endl;
}
