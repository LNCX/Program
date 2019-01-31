#include<cstdio>
#include<iostream>
using namespace std;
int a[9][9],count=0;
bool b[20][5];
void out()
{
	count++;
	printf("No. %d\n",count);
	for(int i=1;i<=8;i++)
	{
		for(int j=1;j<=7;j++)
			printf("%d ",a[i][j]);
		printf("%d",a[i][8]);
		cout<<endl;
	}
}
void dfs(int n)
{
	if(n>8)
	{
		out();
		return;
	}
	for(int i=1;i<=8;i++)
	{
		if(!b[i][1]&&!b[n][2]&&!b[n+i][3]&&!b[n-i+9][4])
		{
			a[i][n]=1;
			b[i][1]=true,b[n][2]=true,
			b[n+i][3]=true,b[n-i+9][4]=true;
			dfs(n+1);
			a[i][n]=0;
			b[i][1]=false,b[n][2]=false,
			b[n+i][3]=false,b[n-i+9][4]=false;
		}
	}
}
int main()
{
	dfs(1);
}

