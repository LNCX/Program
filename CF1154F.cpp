#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=2e5+5;
int a[maxn],f[maxn],dis[maxn];
int main()
{
	int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		a[i]+=a[i-1];
	for(int i=1;i<=m;i++)
    {
		int x,y;
        scanf("%d%d",&x,&y);
		if(x<=k) dis[x]=max(dis[x],y);
	}
	for(int i=1;i<=k;i++)
    {
		f[i]=a[i];
		for(int j=0;j<i;j++)
			f[i]=min(f[i],f[j]+a[i]-a[j+dis[i-j]]);
	}
	cout<<f[k]<<endl;
	return 0;
}