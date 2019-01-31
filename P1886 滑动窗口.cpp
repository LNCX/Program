#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int a[maxn],q[maxn],num[maxn];
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int head=1,tail=0;
	for(int i=1;i<=n;i++)
	{
		int ans;
		while(num[head]<i-k+1&&head<=tail) head++;
		while(a[i]<=q[tail]&&head<=tail) tail--;
		num[++tail]=i;q[tail]=a[i];
		ans=q[head];
		if(i>=k) printf("%d ",ans);
	}
	printf("\n");
	head=1,tail=0;
	for(int i=1;i<=n;i++)
	{
		int ans;
		while(num[head]<i-k+1&&head<=tail) head++;
		while(a[i]>=q[tail]&&head<=tail) tail--;
		num[++tail]=i;q[tail]=a[i];
		ans=q[head];
		if(i>=k) printf("%d ",ans);
	}
	printf("\n");
	return 0;
}
