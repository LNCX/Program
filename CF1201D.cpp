#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5,inf=0x3f3f3f3f3f3f3f3f;
int n,m,k,q,a[N][2],b[N],x,y,f[N][2];
int dis(int j,int u,int i,int v)
{
	int p=lower_bound(b+1,b+q+1,a[j][u])-b,res=inf;
	if(p<=q)res=abs(a[j][u]-b[p])+abs(a[i][v^1]-b[p])+abs(a[i][v]-a[i][v^1]);
	p=upper_bound(b+1,b+q+1,a[j][u])-b-1;
	if(p)res=min(res,abs(a[j][u]-b[p])+abs(a[i][v^1]-b[p])+abs(a[i][v]-a[i][v^1]));
	return res;
}
signed main()
{
    scanf("%lld%lld%lld%lld",&n,&m,&k,&q);
	for(int i=1;i<=n;i++)
        a[i][0]=inf,a[i][1]=-inf;
	for(int i=1;i<=k;i++)
    {
        scanf("%lld%lld",&x,&y);
        a[x][0]=min(a[x][0],y);
        a[x][1]=max(a[x][1],y);
    }
	a[1][0]=1,a[1][1]=max(a[1][1],1ll);
	for(int i=1;i<=q;i++)
        scanf("%lld",&b[i]);
	memset(f,0x3f,sizeof(f));
	sort(b+1,b+q+1);
	f[1][0]=abs(a[1][1]-1)+abs(a[1][1]-a[1][0]),f[1][1]=abs(a[1][1]-1);
    int k=1;
	for(int i=2;i<=n;i++)
    {
		if(a[i][0]==inf) continue;
		for(int v=0;v<2;++v)
            for(int u=0;u<2;++u)
                f[i][v]=min(f[i][v],f[k][u]+dis(k,u,i,v)+i-k);
        k=i;
	}
    printf("%lld\n",min(f[k][0],f[k][1]));
}