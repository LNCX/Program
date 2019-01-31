#include<bits/stdc++.h>
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int ans[1000],ao;
int out[1000],oo;
void dfs(int limit,int h,int ma,int mb)
{
	if(h==limit) return ;
	if(mb%ma==0 && mb/ma>ans[ao-1] && ( oo<=0 || mb/ma < out[oo-1] ))
	{
		ans[ao++]=mb/ma;
		oo=ao;
		memcpy(out,ans,sizeof(ans));
		ao--;
		return ;
	}
	int i=mb/ma-1;
	if(i<=ans[ao-1]) i=ans[ao-1];
	int j=(limit-h)*mb/ma;
	while(++i<=j)
	{
		if(oo>0&&i>=out[oo-1]) return ;
		int g=gcd(i,mb);
		int k=i/g;
		int x=mb*k;
		int y=ma*k-mb/g;
		if(y<0) continue;
		ans[ao++]=i;
		if(y==0)
		{
			oo=ao;
			memcpy(out,ans,sizeof(ans));
			ao--;
			return ;
		}
		dfs(limit,h+1,y,x);
		ao--;
	}
}
int main()
{
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		ao=0;
		oo=0;
		for(int i=1; i<100; i++)
		{
			dfs(i,0,a,b);
			if(oo>0) break;
		}
		for(int i=0; i<oo; i++)
		{
			if(i!=0) printf(" ");
			printf("%d",out[i]);
		}
		printf("\n");
	}
	return 0;
}

