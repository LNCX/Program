#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char map[60][60];
int vis[60][60];
int n,m,i,j,flag;
int dir[4][2]={1,0,0,1,-1,0,0,-1};
void dfs(int x,int y,int parx,int pary,char s)
{
	//vis[x][y]=1;
	int l;
	if(flag==1)
	return ;
	for(l=0;l<4;l++)
	{
		int fx=x+dir[l][0];
		int fy=y+dir[l][1];
		if(fx>=0&&fx<n&&fy>=0&&fy<m&&map[fx][fy]==s)
		{
			if(fx==parx&&fy==pary)
			continue;
			if(vis[fx][fy]==1)
			{
				flag=1;
				return;
			}
			vis[fx][fy]=1;
			dfs(fx,fy,x,y,s);
		}
	}
}
int main()
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i=0;i<n;i++)
		scanf("%s",map[i]);
		flag=0;
		memset(vis,0,sizeof(vis));
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(vis[i][j]==0)
				{
					vis[i][j]=1;
					dfs(i,j,-1,-1,map[i][j]);
				}
				if(flag==1)
				break;
			}
			if(flag==1)
			break;
		}
		if(flag==1)
		printf("Yes\n");
		else
		printf("No\n");
	}
}
