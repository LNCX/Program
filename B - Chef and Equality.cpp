#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int x,n,maxx=-1;
		memset(a,0,sizeof(a));
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&x);	
			a[x]++;
			maxx=max(maxx,a[x]);
		}
		printf("%d\n",n-maxx);
	}
	return 0;
}
