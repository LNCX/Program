#include<cstdio>
int main()
{
	int n,t,a,f[1001]={1};
	scanf("%d%d",&n,&t);
	for(int i =1;i<=n;i++)
	{
		scanf("%d",&a);
		for(int j=t;j>=a;j--)
			f[j]+=f[j-a];
	}
	printf("%d\n",f[t]);
}
