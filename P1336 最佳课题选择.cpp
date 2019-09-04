#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=205,M=25,inf=0x3f3f3f3f3f3f3f3f;
int a[N],b[N],f[N][M];
signed main()
{
	int n,m;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%lld%lld",&a[i],&b[i]);
	for(int i=1;i<=n;i++)
		f[i][1]=a[1]*(int)pow(i,b[1]);
	for(int i=1;i<=n;i++)
		for(int j=2;j<=m;j++)
		{
			f[i][j]=inf;
			for(int k=0;k<=i;k++)
				f[i][j]=min(f[i-k][j-1]+a[j]*(int)pow(k,b[j]),f[i][j]);
		}
	cout<<f[n][m]<<endl;
	return 0;
}