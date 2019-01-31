#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{
	int n,ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		ans=ans^a[i];
	}
	if(ans==0)
	{
		printf("lose\n");
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if((a[i]^ans)<a[i])
		{
			printf("%d %d\n",a[i]-(a[i]^ans),i);
			a[i]=a[i]^ans;
			break;
		}
	}
	for(int i=1;i<=n;i++)
		printf("%d ",a[i]);
	return 0;
}
