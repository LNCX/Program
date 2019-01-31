#include<bits/stdc++.h>
#define lowbit(i) i&(-i)
using namespace std;
int c[500100];
int n,m,a,b,k;
void update(int x,int y)
{
	for(int i=x;i<=n;i+=lowbit(i))
		c[i]+=y;
}
int sum(int x)
{
	int ans=0;
	for(int i=x;i>=1;i-=lowbit(i))
		ans+=c[i];
	return ans;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a);
		update(i,a);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&k,&a,&b);
		if(k==2)
			printf("%d\n",sum(b)-sum(a-1));
		else update(a,b);
	}
}
