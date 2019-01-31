#include<cstdio>
#include<iostream>
using namespace std;
int n,a[10][10],map[10][10][10],ans[10][3];
void data(int step,bool flag)
{
	for(int x=1;x<=5;x++)
	for(int y=1;y<=7;y++)
		if(flag)
			map[x][y][step]=a[x][y];
		else 
			a[x][y]=map[x][y][step];
}
bool scan()
{
	for(int x=1;x<=5;x++)
	for(int y=1;y<=7;y++)
		if(a[x][y]) return false;
	return true;
}
bool anih()
{
	bool flag=false;
	bool used[10][10]={false};
	for(int x=1;x<=5;x++)
		for(int y=1;y<=7;y++)
		{
			if(x-1>=1&&x+1<=5&&a[x][y]&&a[x][y]==a[x-1][y]&&a[x][y]==a[x+1][y])
			{
				used[x-1][y]=true;
				used[x+1][y]=true;
				used[x][y]=true;
				flag=true;
			}
			if(y-1>=1&&y+1<=7&&a[x][y]&&a[x][y]==a[x][y+1]&&a[x][y]==a[x][y-1])
			{
				used[x][y]=true;
				used[x][y+1]=true;
				used[x][y-1]=true;
				flag=true;
			}
		}
	if(!flag)return false;
	for(int x=1;x<=5;x++)
	for(int y=1;y<=7;y++)
		if(used[x][y])
		{
			used[x][y]=0;
			a[x][y]=0;
		}
	return true;
}
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
void dfs(int step)
{
	if(step>n)
	{
		data(step,true);
		do{down();}while(anih());
		if(scan())
		{
			for(int i=1;i<step;i++)
				printf("%d %d %d\n",ans[i][0]-1,ans[i][1]-1,ans[i][2]);
			exit(0);
		}
		
		/*if(ans[1][0]==3&&ans[1][1]==2&&ans[1][2]==1)
		if(ans[2][0]==4&&ans[2][1]==2&&ans[2][2]==1)
		if(ans[3][0]==4&&ans[3][1]==1&&ans[1][2]==1)
		{
			cout<<endl;
			for(int i=1;i<=step;i++)
			{
				for(int x=1;x<=5;x++)
				{
					for(int y=1;y<=7;y++)
					{
						printf("%d ",map[x][y][i]);
					}
					cout<<endl;
				}
				cout<<endl;
			}
			exit(0);	
		}*/
		data(step,false);
		return;
	}
	for(int x=1;x<=5;x++)
	for(int y=1;y<=7;y++)
	{
		if(!a[x][y]) break;
		data(step,true);
		if(x<5)
		{
			swap(a[x][y],a[x+1][y]);
			ans[step][0]=x,ans[step][1]=y,ans[step][2]=1;
			do{down();}while(anih());
			/*
			cout<<endl;
			if(ans[1][0]==3&&ans[1][1]==1)
			for(int x=1;x<=5;x++)
				{
					for(int y=1;y<=7;y++)
					{
						printf("%d ",a[x][y]);
					}
					cout<<endl;
				}
				cout<<endl;
			*/		
			dfs(step+1);
			data(step,false);
		}
		if(x>1&&!a[x-1][y])
		{
			swap(a[x][y],a[x-1][y]);
			ans[step][0]=x,ans[step][1]=y,ans[step][2]=-1;
			do{down();}while(anih());
			dfs(step+1);
			data(step,false);
		}
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<=5;i++)
	for(int j=1,x;j<=7;j++)
	{
		scanf("%d",&x);
		if(x==0) break;
		a[i][j]=x;
	}
	dfs(1);
	cout<<-1<<endl;
}
