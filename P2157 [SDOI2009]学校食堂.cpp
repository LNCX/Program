#include<bits/stdc++.h>
#define cost(a,b) ((t[a]|t[b])-(t[a]&t[b]))
using namespace std;
const int N=1000,inf=0x3f3f3f3f;
int n,t[N+1],b[N+1],f[N+2][16][1<<7];
bool valid(int x,int s,int k)
{
	for (int i=x+1;i<k;i++)
		if (!(s&(1<<(i-x-1)))&&i+b[i]<k)
			return false;
	return true;
}
int dp()
{
	memset(f,inf,sizeof(f));
	f[2][7][0]=0;
	for(int i=1;i<=b[1]&&1+i<=n;i++)
		if (valid(1, 0, 1+i))
			f[1][i+8][1<<(i-1)]=0;
	for(int i=1;i<=n;++i)
		for(int k=0;k<(1<<7);k++)
			for(int j=max(0,9-i);j<16;j++)
			{
				if (f[i][j][k]==inf) continue;
				int p=0;
				while(k&(1<<p)) p++;p++;
				f[i+p][8-p][k>>p]=min(f[i+p][8-p][k>>p],f[i][j][k]+cost(i+j-8,i));
				for (int l=i+1;l<=i+b[i]&&l<=n;l++)
					if (!(k&(1<<(l-i-1)))&&valid(i,k,l))
						f[i][l-i+8][k|(1<<(l-i-1))]=min(f[i][l-i+8][k|(1<<(l-i-1))], f[i][j][k]+cost(i+j-8,l));
			}
	int ans=1<<30;
	for (int j=0;j<16;j++)
		if (f[n+1][j][0]<inf)
			ans=min(ans,f[n+1][j][0]);
	return ans;
}

int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d", &n);
		for (int i=1;i<=n;i++)
			scanf("%d %d",&t[i],&b[i]);
		printf("%d\n",dp());
	}
	return 0;
}
