#include<iostream>
#define max 101
using namespace std;
int ans,area,a[max][max],b[max][max];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		cin>>a[i][j];
		b[i][j]=a[i][j]+b[i][j-1];
	}
	ans=a[1][1];
	for(int l=1;l<=n;l++)
	for(int r=l;r<=n;r++)
	{
		area=0;
		for(int i=1;i<=n;i++)
		{
			area+=b[i][r]-b[i][l-1];
			if(area>ans) ans=area;
			if(area<0) area=0;
		}
	}
	cout<<ans<<endl;
}
