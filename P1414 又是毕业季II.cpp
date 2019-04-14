#include<bits/stdc++.h>
const int maxn=1e6+5;
int n,a[maxn],c[maxn],maxx;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d", &x);
		a[x]++;
		maxx=std::max(maxx,x);
	}
	for(int i=1;i<=maxx;i++)
	{
		int cnt=0;
		for(int j=1;i*j<=maxx;j++)	
			cnt+=a[i*j];
		for(int j=1;j<=cnt;j++)
			c[j]=std::max(c[j],i);
	}
	for(int i=1;i<=n;i++)
		printf("%d\n", c[i]);
	return 0;
}
