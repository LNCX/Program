#include<bits/stdc++.h>
using namespace std;
int f[5005];
int find(int x)
{
	while(x!=f[x]) x=f[x];
	return x;
}
int main()
{
	int n,m,p;
	scanf("%d%d%d",&n,&m,&p);
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		f[find(x)]=find(y);
	}
	for(int i=1;i<=p;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(find(x)==find(y))	printf("Yes\n");
		else printf("No\n");
	}
}

