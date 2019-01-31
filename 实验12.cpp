#include<bits/stdc++.h>
using namespace std;
int a[10][10];
int main()
{
	int i,j,n,k=0,cnt;
	cin>>n;
	cnt=1;
	while(cnt<=n*n)
	{
		for(i=1+k;i<=n-k-1;i++)	
			a[i][n-k]=cnt++;
		for(j=n-k;j>=1+k+1;j--) a[n-k][j]=cnt++;
		for(i=n-k;i>=1+k+1;i--) a[i][1]=cnt++;
		for(j=1+k;j<=n-k-1;j++) a[1][j]=cnt++;	
		k++;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			printf("%d ",a[i][j]);
		cout<<endl;
	}
}
