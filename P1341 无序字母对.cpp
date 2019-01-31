#include<bits/stdc++.h>
using namespace std;
int n,dg[60],g[60][60],ans[2005],len;
int f1(char x)
{
	if(x<='z'&&x>='a') return x-'a'+27;
    return x-'A'+1;
}
int f2(char x)
{
    if(x<=26) return 'A'+x-1;
    return 'a'+x-27;
}
void read()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		char x,y;
		cin>>x>>y;
		g[f1(x)][f1(y)]=1,dg[f1(x)]++;
		g[f1(y)][f1(x)]=1,dg[f1(y)]++;
	}
}
void dfs(int u)
{
	for(int v=1;v<=52;v++)
		if(g[u][v])
		{
			g[u][v]=g[v][u]=0;
			dfs(v);
		}
	ans[++len]=u;
}
int main()
{
	int start=0x3f3f3f3f,cnt=0;
	read();
	for(int i=1;i<=52;i++)
		if(dg[i]%2==1)
		{
			start=min(start,i);
			cnt++;
		}
	if(cnt!=0&&cnt!=2)
	{
		printf("No Solution\n");
		return 0;
	}
	if(cnt==0)
		for(int i=1;i<=52;i++)
			if(dg[i])
			{
				start=i;
				break;	
			}
	dfs(start);
	for(int i=len;i>=1;i--)
		printf("%c",f2(ans[i]));
}
