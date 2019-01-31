#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	int m=1,n=1,flag=0;
	int dx[4]={-1,0,1,0},
		dy[4]={0,1,0,-1};
	while(1)
	{
		flag=0;
		cin>>m>>n;
		if(m==0&&n==0) return 0;
		bool b[25][25]={0};
		char p[m][n];
		int a[1005][3],c[1005]={0},head=0,tail=1,count=0;
		for(int i=0;i<m;i++)	
			cin>>p[i];
		for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			if(p[i][j]=='@')
			{
				a[1][1]=i;
				a[1][2]=j;
				b[i][j]=true;	
			}	
		do
		{
			head++;
			int x,y;
			for(int i=0;i<=3;i++)
			{
				x=a[head][1]+dx[i],y=a[head][2]+dy[i];
				if(x>=0&&y>=0&&x<m&&y<n&&p[x][y]!='#'&&!b[x][y])
				{
					tail++;
					a[tail][1]=x,a[tail][2]=y;
					b[x][y]=1;
					c[tail]=head;
				}
				if(p[x][y]=='*')
				{
					head=tail;
					flag=1;
					int d=tail;
					while(c[d])
					{
						count++;
						d=c[d];
					}
					break;
				}
			}
		}while(head<tail);
		if(flag==0) cout<<-1<<endl;
		else cout<<count<<endl;
	}
	return 0;
}

