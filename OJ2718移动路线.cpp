#include<iostream>
using namespace std;
int main()
{
	int m,n,f[20][20]={0};
	cin>>m>>n;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
		{
			if(i==1&&j==1) f[i][j]=1;
			else if(i==1) f[i][j]=f[i][j-1];
			else if(j==1) f[i][j]=f[i-1][j];
			else f[i][j]=f[i-1][j]+f[i][j-1];
		}
	cout<<f[m][n]<<endl;
}
