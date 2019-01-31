#include<bits/stdc++.h>
using namespace std;
int a[10][10];
void down()
{
	for(int x=1;x<=5;x++)
	{
		int cnt=0;
		for(int y=1;y<=7;y++)
			if(!a[x][y]) cnt++;
			else
			{
				int mid=a[x][y];
				a[x][y]=0;
				a[x][y-cnt]=mid;
			}
	}
}
int main()
{
	int n; 
	cin>>n;
	for(int i=1;i<=5;i++)
	for(int j=1,x;j<=7;j++)
	{
		scanf("%d",&x);
		if(x==0) break;
		a[i][j]=x;
	}
	swap(a[5][4],a[4][4]);
	down();
	
	cout<<endl;
	for(int x=1;x<=5;x++)
	{
		for(int y=1;y<=7;y++)
		{
			printf("%d ",a[x][y]);
		}
		cout<<endl;
	}
	cout<<endl;
	
}

