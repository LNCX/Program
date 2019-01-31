#include<stdio.h>
int a[10];
int b[105];
int main()
{
	a[0]=5;a[1]=0;a[2]=10;a[3]=7;a[4]=1;
	int n,sum,max,i,j;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=1;i<=n;i++) scanf("%d",&b[i]);
		int Max=0;
		for(i=1;i<=n;i++)
		{
            sum=0,max=0;
			for(j=i;j<=n;j++)
			{
				sum+=a[b[j]];
				if(sum>max) max=sum;
				if(b[j]==2&&j<n) sum+=1;
				if(b[j]==4&&j<n) sum-=2;
			}
			if(max>Max) Max=max;
		}
		printf("%d\n",Max);
	}
}
