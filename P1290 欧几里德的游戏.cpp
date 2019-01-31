#include<bits/stdc++.h>
using namespace std;
int dfs(int a,int b,int p)
{
	if(b==a)return 1;
	if(b/a>=2)return 1;
	else return 1^dfs(b-a,a,p^1);
}
int main()
{
	int n,m,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		if(n>m)swap(n,m);
		if(dfs(n,m,1)==0)
			 printf("Ollie wins\n");
		else printf("Stan wins\n");
	}
}
