#include<iostream>
using namespace std;
long long a[41][41],f[41][41];
int main()
{
	char aa;
	long long n,k;
	cin>>n>>k;
	getchar();
	for(int i=1;i<=n;i++)
	{
		aa=getchar();
		a[i][i]=aa-'0';
	}
	for(int i=1;i<n;i++)
	for(int j=i+1;j<=n;j++)
		a[i][j]=a[i][j-1]*10+a[j][j];
	for(int i=1;i<=n;i++)
		f[i][0]=a[1][i];
	for(int i=1;i<=n;i++)
	for(int k1=1;k1<i&&k1<=k;k1++)
	for(int j=k1;j<i;j++)
		f[i][k1]=max(f[i][k1],f[j][k1-1]*a[j+1][i]);
	cout<<f[n][k];
}
