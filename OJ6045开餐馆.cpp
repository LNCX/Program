#include <stdio.h>
int m[110]={-999},p[110],f[110]={0};
int max(int a,int b){return a>b?a:b;}
int main()
{
	int T,n,k,i,j,t;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(i=1;i<=n;i++) scanf("%d",&m[i]);
		for(i=1;i<=n;i++) scanf("%d",&p[i]);
		for(i=1;i<=n;i++)
		{
			t=i-1;
			while(m[i]-m[t]<=k) t--;
			f[i]=max(f[i-1],f[t]+p[i]);
		}
		printf("%d\n",f[n]);
	}
	return 0;
}
