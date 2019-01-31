#include<bits/stdc++.h>
#define lowbit(x) (x&(-x))
using namespace std;
int n,m;
const int maxn=1e5+5;
int c[maxn];
void fix(int x)
{
	while(x>0)
	{
		c[x]++;
		x-=lowbit(x);
	}
}
int ask(int x)
{
	int res=0;
	while(x<=n)
	{
		res+=c[x];
		x+=lowbit(x);
	}
	return res;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int t;
		scanf("%d",&t);
		if(t==1)
		{
			int l,r;
			scanf("%d%d",&l,&r);
			fix(r),fix(l-1);
		}
		else if(t==2)
		{
			int x;
			scanf("%d",&x);
			printf("%d\n",ask(x)%2);
		}
	}
	return 0;
}
