#include<bits/stdc++.h>
using namespace std;
int a[100][100];
int ack(int m,int n)
{
	if(m==0)
	{
		a[m][n]=n+1;
		return a[m][n];
	}
	else if(n==0)
	{
		a[m][n]=ack(m-1,1);
		return a[m][n];
	}
	else
	{
		a[m][n]=ack(m-1,ack(m,n-1));
		return a[m][n];
	}
}
int main()
{
	freopen("ack.xls","w",stdout);
	cout<<ack(3,4)<<endl;
	for(int i=0;i<20;i++)
	{
		for(int j=0;j<20;j++)
			cout<<a[i][j]<<"\t";
		cout<<endl;
		
	}
}
