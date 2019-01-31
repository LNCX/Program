#include<bits/stdc++.h>
using namespace std;
int n,m,r,c,a[20][20];
int h[20],f[20][20];
void dp()
{
	for(int i=1;i<=r;i++)
		
}
void dfs(int x,int now)
{
	if(x>r)
	{
		dp();
		return ;	
	} 
	for(int i=now;i<=n;i++)
		if(!used[i])
		{
			used[i]=true;
			h[x]=i;
			dfs(x+1,i+1);
			used[i]=false;
			h[x]=0;
		}
}
int main()
{
	cin>>n>>m>>r>>c;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
		scanf("%d",a[i][j]);	
	dfs(1,1);
}

