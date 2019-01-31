#include<iostream>
using namespace std;
int n,k,f[201][7];
int main()
{
	cin>>n>>k;
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=k; j++)
		{
			f[i][1]=1;
			f[0][j]=1;
			if(j>i) f[i][j]=f[i][i];
			else f[i][j]=f[i-j][j]+f[i][j-1];
		}
	}
	cout<<f[n][k]-f[n][k-1]<<endl;
	return 0;
}
