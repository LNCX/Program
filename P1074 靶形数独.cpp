#include<bits/stdc++.h>
using namespace std;
struct node
{
	int line;
	int num;
}n[10];
int ans=0,used[10][2][10],
	a[10][10],b[10][10],c[10][10];
bool cmp(node a,node b){return a.num<b.num;}
int cub(int x,int y){return (x+2)/3+3*((y+2)/3-1);}
int sum()
{
    int len=0;
    for(int i=1;i<=9;i++)
    for(int j=1;j<=9;j++)
        len+=a[i][j]*c[i][j];
    if(len>ans) ans=len;
}
void dfs(int x,int y)
{
	int tx=n[x].line;
	if(x==10){sum();return;}
	if(a[tx][y]!=0) dfs(x+y/9,y%9+1);
	else
	for(int k=1;k<=9;k++)
	{
		if(!b[cub(tx,y)][k]&&!used[tx][0][k]&&!used[y][1][k])
		{
			used[tx][0][k]=true;
			used[y][1][k]=true;
			b[cub(tx,y)][k]=true;
			a[tx][y]=k;
			dfs(x+y/9,y%9+1);
			used[tx][0][k]=false;
			used[y][1][k]=false;
			b[cub(tx,y)][k]=false;
			a[tx][y]=0;
		}
	}
}
int main()
{
	for(int i=1;i<=9;i++)
	{
		int count=0;
		for(int j=1;j<=9;j++)
		{
			scanf("%d",&a[i][j]);
			int mid=a[i][j];
			if(mid)
			{
				used[i][0][mid]=true;
				used[j][1][mid]=true;
				b[cub(i,j)][mid]=true;
			}
			else count++;
		}
		n[i].line=i;
		n[i].num=count;
	}
	sort(n+1,n+10,cmp);
	for(int i=0;i<=4;i++)
	for(int j=5-i;j<=5+i;j++)
	for(int k=5-i;k<=5+i;k++)
		if(c[j][k]==0)
			c[j][k]=10-i;	
	dfs(1,1);
	if(ans==0)	ans=-1;
	cout<<ans<<endl;
}
