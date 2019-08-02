#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3002;
ll g,x,y,z;
int n,m,aa,bb;
int a[N][N],b[N][N],c[N][N],q[N];
int main()
{
	scanf("%d%d%d%d",&n,&m,&aa,&bb);
	scanf("%lld%lld%lld%lld",&g,&x,&y,&z);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
        {
			a[i][j]=g;
			g=(g*x+y)%z;
		}
	for(int i=1;i<=n;i++)
    {
		int l=1,r=0;
		for(int j=1;j<=m;j++)
        {
			if(l<=r&&j-q[l]+1>bb) l++;
			while(l<=r&&a[i][j]<=a[i][q[r]])r--;
			q[++r]=j;
			b[i][j]=a[i][q[l]];
		}
	}
	for(int j=1;j<=m;j++)
    {
		int l=1,r=0;
		for(int i=1;i<=n;i++)
        {
			if(l<=r&&i-q[l]+1>aa) l++;
			while(l<=r&&b[i][j]<=b[q[r]][j])r--;
			q[++r]=i;
			c[i][j]=b[q[l]][j];
		}
	}
	ll ans=0;
	for(int i=aa;i<=n;i++)
		for(int j=bb;j<=m;j++)
			ans+=c[i][j];
	printf("%lld\n",ans);
	return 0;
}