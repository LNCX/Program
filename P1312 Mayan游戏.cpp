#include<bits/stdc++.h>
using namespace std;
bool used[10][10];
int n,a[10][10],back[10][10][10],ans[10][3];
bool color()
{
	int b[15]={0};
	for(int x=1;x<=5;x++)
	for(int y=1;y<=7;y++)
		b[a[x][y]]++;
	for(int i=1;i<=10;i++)
		if(1<=b[i]&&b[i]<=2)
			return false;
	return true;
}
void data(int step,bool flag)
{
	for(int x=1;x<=5;x++)
	for(int y=1;y<=7;y++)
		if(flag)
			back[x][y][step]=a[x][y];
		else 
			a[x][y]=back[x][y][step];
}
bool scan()
{
	for(int x=1;x<=5;x++)
		if(a[x][1]) return false;
	return true;
}
bool anih()
{
	bool flag=false;
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
	if(!color())return;
	if(step>n)
	{
		if(scan())
		{
			for(int i=1;i<step;i++)
				printf("%d %d %d\n",ans[i][0],ans[i][1],ans[i][2]);
			exit(0);
		}
		return;
	}
	for(int x=1;x<=5;x++)
	for(int y=1;y<=7;y++)
	{
		if(!a[x][y]) break;
		data(step,true);
		if(x<=4&&a[x][y]!=a[x+1][y])
		{
			swap(a[x][y],a[x+1][y]);
			ans[step][0]=x-1,ans[step][1]=y-1,ans[step][2]=1;
			do{down();}while(anih());
			dfs(step+1);
			data(step,false);
		}
		if(x>=2&&!a[x-1][y])
		{
			swap(a[x][y],a[x-1][y]);
			ans[step][0]=x-1,ans[step][1]=y-1,ans[step][2]=-1;
			do{down();}while(anih());
			dfs(step+1);
			data(step,false);
		}
	}
}
int main()
{
	scanf("%d",&n);
	for(int x=1;x<=5;x++)
	for(int y=1;y<=7;y++)
	{
		int mid;
		scanf("%d",&mid);
		if(mid==0) break;
		a[x][y]=mid;
		if(y==7) scanf("%d",&mid);
	}
	dfs(1);
	printf("-1\n");
}
