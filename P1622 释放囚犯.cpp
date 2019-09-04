#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5,M=105,inf=0x3f3f3f3f;
int n,m,a[M],f[N][N];
int find(int x)
{
	int l=1,r=m+1,res=0;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(a[mid]<=x) l=mid+1,res=mid;
		else r=mid-1;
 	}
 	return res;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d",&a[i]);
	a[m+1]=inf;
	sort(a+1,a+1+m);
	for(int len=1;len<=n;len++)
		for(int l=1;l+len<=n;l++)
		{
			int r=l+len;
			f[l][r]=inf;
			for(int p=find(l);a[p]<=r;p++)
			{
				int k=a[p];
				f[l][r]=min(f[l][k-1]+f[k+1][r]+r-l,f[l][r]);
			}
			if(f[l][r]==inf) f[l][r]=0;
			
		}
	cout<<f[1][n]<<endl;
	return 0;
}