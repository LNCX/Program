#include<bits/stdc++.h>
using namespace std;
int n,q,l[105],r[105],f[105][105],mapn[105][105],a[105];
void build(int v)
{
	for(int i=1;i<=n;i++)
		if(mapn[v][i]>=0)
		{
			l[v]=i;a[i]=mapn[v][i];
			mapn[v][i]=mapn[i][v]=-1;
			build(i);
			break;
		}
	for(int i=1;i<=n;i++)
		if(mapn[v][i]>=0)
		{
			r[v]=i;a[i]=mapn[v][i];
			mapn[v][i]=mapn[i][v]=-1;
			build(i);
			break;
		}
}
int DP(int i,int j)
{
	if(j==0) return 0;
	if((l[i]==0)&&(r[i]==0)) return a[i];
	if(f[i][j]>0) return f[i][j];
	for(int k=0;k<=j-1;k++)
		f[i][j]=max(f[i][j],DP(l[i],k)+DP(r[i],j-k-1)+a[i]);
	return f[i][j];
}
int main()
{
	cin>>n>>q;q++;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			mapn[i][j]=-1;
	for(int i=1;i<=n-1;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		mapn[x][y]=mapn[y][x]=z;
	}
	build(1);
	cout<<DP(1,q)<<endl;
	return 0;
}
