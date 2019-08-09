#include<bits/stdc++.h>
using namespace std;
const int N=105;
const int inf=0x3f3f3f3f;
int g[N][N];
int main()
{
	int n,k,f,t;
	scanf("%d%d%d",&n,&f,&t);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			g[i][j]=inf;
			g[i][i]=0;
		}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k);
		for(int j=1;j<=k;j++)
		{
			int a;
			scanf("%d",&a);
			if(j==1)g[i][a]=0;
			else g[i][a]=1;
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
	if(g[f][t]==inf) cout<<-1<<endl;
	else printf("%d",g[f][t]);
}
