#include<bits/stdc++.h>
using namespace std;
struct node
{
	int a,b;
}p[1005];
int n,lensum,lenans,lenmid; 
long long mod=1e13,sum[1005]={1},ans[1005],mid[1005];
bool cmp(node x,node y){return x.a*x.b<y.a*y.b;}

void mul(int x)
{
	for(int i=0;i<lensum;i++)
		sum[i]*=x;
	for(int i=0;i<lensum;i++)
	{
		sum[i+1]+=sum[i]/mod;
		sum[i]%=mod;
	}
	if(sum[lensum]) lensum++;
}
void div(int x)
{
	lenmid=lensum;
	for(int i=0;i<lensum;i++)	mid[i]=sum[i];
	for(int i=lenmid-1;i>=0;i--)
	{
		if(i>0)	mid[i-1]+=mid[i]%x*mod;
		mid[i]/=x;
	}
	while(!mid[lenmid-1]&&lenmid>=1) lenmid--;
}
bool max()
{
	if(lenmid<lenans) return 0;
	if(lenmid>lenans) return 1;
	for(int i=lenans-1;i>=0;i--)
		if(mid[i]>ans[i]) return 1;
		else if(mid[i]<ans[i]) return 0;
	return 0;
}
void swap()
{
	lenans=lenmid;
	for(int i=lenans-1;i>=0;i--)
		ans[i]=mid[i];
}
int main()
{
	cin>>n;
	for(int i=0;i<=n;i++)
		scanf("%d%d",&p[i].a,&p[i].b);
	sort(p+1,p+n+1,cmp);
	sum[0]=lensum=1;
	for(int i=1;i<=n;i++)
	{
		mul(p[i-1].a);
		div(p[i].b);
		if(max())
			swap();
	}
	printf("%lld",ans[lenans-1]);
	for(int i=lenans-2;i>=0;i--)
		printf("%013lld",ans[i]);
}
