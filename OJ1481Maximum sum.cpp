#include<cstdio>
#define max(a,b) ((a)>(b))?(a):(b) 
int a[50010],f1[50010],f2[50010];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,i,ans=-10000000,tmp=0;
		scanf("%d",&n);
		f1[0]=f2[n+1]=-10000000;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			tmp=max(tmp+a[i],a[i]);
			f1[i]=max(f1[i-1],tmp);
		}
		tmp=0;
		for(i=n;i>=2;i--)
		{
			tmp=max(tmp+a[i],a[i]);
			f2[i]=max(f2[i+1],tmp);
			ans=max(ans,f2[i]+f1[i-1]);
		}
		printf("%d\n",ans);
	}
	return 0;
}
