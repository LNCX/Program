#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	char a[n+1][m+1];
	for(int i=1;i<n+1;i++)
	for(int j=1;j<m+1;j++)
		cin>>a[i][j];
	char b[n][m];
	for(int i=1;i<n+1;i++)
	for(int j=1;j<m+1;j++)
	{
		int count=0;
		if(a[i][j]=='*') b[i][j]='*';
		else
		{
			for(int x=-1;x<=1;x++)
			for(int y=-1;y<=1;y++)
			if(a[i+x][j+y]=='*') count++;
			b[i][j]=count+48;
		}
	}
	for(int i=1;i<n+1;i++)
	{
		for(int j=1;j<m+1;j++)	
		{
			cout<<b[i][j];
		}
		cout<<endl;
	}
}

