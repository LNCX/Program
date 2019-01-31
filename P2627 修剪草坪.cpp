#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
long long f[maxn][2],a[maxn],sum[maxn],q[maxn];
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		sum[i]=sum[i-1]+a[i];	
	}
	int l=1,r=1;
	for(int i=1;i<=n;i++)
	{
		f[i][0]=max(f[i-1][0],f[i-1][1]);
		while(q[l]<i-k&&l<=r) l++;
		f[i][1]=f[q[l]][0]-sum[q[l]]+sum[i];
		while(f[i][0]-sum[i]>f[q[r]][0]-sum[q[r]]&&l<=r) r--;
		q[++r]=i;
	}
	printf("%lld\n",max(f[n][0],f[n][1]));
	return 0;
}
