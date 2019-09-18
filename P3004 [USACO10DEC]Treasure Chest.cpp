#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
int n,a[N],sum[N],f[N][2],g[N][2];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),sum[i]=sum[i-1]+a[i];
    for(int i=1;i<=n;i++)
		f[i][0]=f[i][1]=a[i];
    for(int len=1;len<=n;len++)
	{
        for(int l=1;l+len<=n;l++)
        {
            int r=len+l;
			g[l][0]=max(sum[r-1]-sum[l-1]-f[l][1]+a[r],sum[r]-sum[l]-f[l+1][1]+a[l]);
			g[l][1]=max(sum[r-1]-sum[l-1]-f[l][0]+a[r],sum[r]-sum[l]-f[l+1][0]+a[l]);
        }
		for(int l=1;l<=n;l++)
		{
			f[l][0]=g[l][0];
			f[l][1]=g[l][1];
		}
	}
    printf("%d\n",f[1][0]);
    return 0;
}
