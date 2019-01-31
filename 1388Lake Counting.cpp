#include<cstdio>
#include<iostream>
#define maxn 10005
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	char a[105][105];
	bool b[105][105]={0};
	int q[maxn][2]={0},count=0,
	dx[4]={-1,0,1},dy[4]={-1,0,1};
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	{
		if(a[i][j]=='W'&&b[i][j]==false)
		{
			int x,y,head=0,tail=1;
			q[1][0]=i,q[1][1]=j,b[i][j]=true;
			do
			{
				head++;
				for(int k=0;k<3;k++)
				for(int s=0;s<3;s++)
				{
					int x=q[head][0]+dx[k],y=q[head][1]+dy[s];
					if(0<=x&&x<n&&0<=y&&y<m&&a[x][y]=='W'&&b[x][y]==false)
					{
						tail++;
						q[tail][0]=x;
						q[tail][1]=y;
						b[x][y]=true;
					}
				}
			}while(head<tail);
			count++;
		}
	}
	cout<<count<<endl;
}

