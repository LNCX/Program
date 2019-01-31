#include<bits/stdc++.h>
using namespace std;
int n,m,a[205][205],f[205][205];
int main()
{
	cin>>n>>m;
	int x=n,y=m/2+1;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
		scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
		f[i][j]=max(max(f[i-1][j],f[i-1][j-1]),f[i-1][j+1])+a[i][j];
	cout<<max(max(f[x][y],f[x][y-1]),f[x][y+1])<<endl;
}

