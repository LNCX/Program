#include<bits/stdc++.h>
using namespace std;
int n,m,ans1,ans2,a[2005][2005];
int l[2005][2005],r[2005][2005],h[2005][2005];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		scanf("%d",&a[i][j]);
		l[i][j]=r[i][j]=j;
		h[i][j]=1;
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
		if(a[i-1][j]^a[i][j])
			h[i][j]=h[i-1][j]+1;
	for(int i=1;i<=n;i++)
	for(int j=2;j<=m;j++)
		if(a[i][j-1]^a[i][j])
			l[i][j]=l[i][j-1];
	for(int i=1;i<=n;i++)
	for(int j=m-1;j>0;j--)
		if(a[i][j+1]^a[i][j])
			r[i][j]=r[i][j+1];
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		if(i>1&&a[i][j]^a[i-1][j])
		{
			l[i][j]=max(l[i][j],l[i-1][j]);
			r[i][j]=min(r[i][j],r[i-1][j]);
		}
		int x=r[i][j]-l[i][j]+1;
		int y=min(x,h[i][j]);
		ans1=max(ans1,y*y);
		ans2=max(ans2,x*h[i][j]);
	} 
	printf("%d\n%d\n",ans1,ans2);
}
