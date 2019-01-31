#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,l,a,x,y,ans=0;
	scanf("%d%d%d",&n,&l,&a);
	int mid=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&x,&y);
		ans+=(x-mid)/a;
		mid=x+y;
	}
	ans+=(l-mid)/a;
	printf("%d",ans);
}
