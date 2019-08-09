#include<bits/stdc++.h>
using namespace std;
const int N=1005;
const int inf=0x7fffffff;
struct node
{
	int v;
	int k;
	int c;
	int l;
}a[N];
bool cmp(node x,node y){return x.v<y.v; }
int s[N],f[N];
int main()
{
	int n;
	while(scanf("%d",&n),n!=0)
	{
		for(int i=1;i<=n;i++)
			scanf("%d%d%d%d",&a[i].v,&a[i].k,&a[i].c,&a[i].l);
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++)
		{
			s[i]=s[i-1]+a[i].l;
			f[i]=inf;
		} 
		for(int i=1;i<=n;i++)
			for(int j=0;j<i;j++)
				f[i]=min(f[i],f[j]+(s[i]-s[j])*a[i].c+a[i].k);
		printf("%d\n",f[n]);
	}
    return 0;
}
