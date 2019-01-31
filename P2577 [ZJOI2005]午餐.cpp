#include<bits/stdc++.h>
using namespace std;
struct stu
{
	int a;
	int b;
}m[205];
int cmp(stu x,stu y)
{
	return x.b>y.b;
}
int n,f[205][205*205],t[205],ans=0x3f3f3f3f;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&m[i].a,&m[i].b);
	sort(m+1,m+1+n,cmp);
	for(int i=1;i<=n;i++)
		t[i]=t[i-1]+m[i].a;
	memset(f,ans,sizeof(f));
	f[0][0]=0;
	for(int i=1;i<=n;i++)
		for(int j=t[i];j>=0;j--)
		{
			if(j>=m[i].a)
				f[i][j]=min(f[i][j],max(f[i-1][j-m[i].a],j+m[i].b));
			f[i][j]=min(f[i][j],max(f[i-1][j],t[i]-j+m[i].b));
		}
	for(int i=0;i<=t[n];i++)
		ans=min(ans,f[n][i]);
	printf("%d\n",ans);
}
