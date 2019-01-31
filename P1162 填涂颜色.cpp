#include<cstdio>
#include<iostream>
using namespace std;
int n,a[35][35],dx[5]={0,1,-1,0,0},dy[5]={0,0,0,1,-1};
void bfs(int x,int y)
{
	int head=0,tail=1,que[1005][2]={0};
	que[1][0]=x,que[1][1]=y;
	a[x][y]=3;
	while(head<=tail)
	{
		head++;
		for(int i=1;i<=4;i++)
		{
			int tx=dx[i]+que[head][0],ty=dy[i]+que[head][1];
			if(1<=tx&&tx<=n&&1<=ty&&ty<=n&&a[tx][ty]==0)
			{
				tail++;
				que[tail][0]=tx,que[tail][1]=ty;
				a[tx][ty]=3;	
			}
		}
	}
	
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
		scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
		if((i==1||j==1||i==n||j==n)&&a[i][j]==0)
			bfs(i,j);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		if(a[i][j]==3)	printf("0 ");
		else if(a[i][j]==0) printf("2 ");
		else printf("1 ");
		if(j==n) printf("\n");
	}
}
