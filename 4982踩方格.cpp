#include<cstring>
#include<iostream>
using namespace std;
int main()
{
	int n,f[21][3]={{0,0,0},{1,1,1}};
	cin>>n;
	for(int i=2;i<=n;i++)
	{
		f[i][0]=f[i-1][0]+f[i-1][1]+f[i-1][2];
		f[i][1]=f[i-1][0]+f[i-1][1];
		f[i][2]=f[i-1][0]+f[i-1][2];
	}
	cout<<f[n][0]+f[n][1]+f[n][2]<<endl;
}
