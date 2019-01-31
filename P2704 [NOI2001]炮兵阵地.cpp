#include<iostream>
#include<cstdio>
using namespace std;
int n,m,cnt,a[105];
int s[65],g[65],f[102][65][65],ans;
int get(int x)
{
	int e=0;
	while(x>0)
	{
		++e;
		x-=x&(-x);
	}
	return e;
}
void init()
{
	for(int i=1;i<=n;i++)
	{
		char s[15];
		scanf("%s",s);
		for(int j=0;j<m;j++)
			if(s[j]=='H')
				a[i]+=1<<j;
	}
	for(int i=0;i<(1<<m);i++)
		if(((i&(i<<1))==0)&&((i&(i<<2))==0)&&((i&(i>>1))==0)&&((i&(i>>2))==0))
		{
			s[++cnt]=i;
			g[cnt]=get(i);
			if((i&a[1])==0) 
				f[1][0][cnt]=g[cnt];
		}
	for(int i=1;i<=cnt;i++)
		for(int j=1;j<=cnt;j++)
			if(((s[i]&s[j])==0)&&((s[j]&a[2])==0)) 
				f[2][i][j]=max(f[2][i][j],f[1][0][i]+g[j]);
}
void DP()
{
	for(int i=3;i<=n;i++)
		for(int j=1;j<=cnt;j++)
			if((a[i]&s[j])==0)
				for(int k=1;k<=cnt;k++)
					if((s[k]&s[j])==0)
						for(int t=1;t<=cnt;t++)
							if(((s[t]&s[k])==0)&&((s[t]&s[j])==0))
								f[i][k][j]=max(f[i][k][j],f[i-1][t][k]+g[j]);
	for(int i=1;i<=cnt;i++)
		for(int j=1;j<=cnt;j++)
			ans=max(f[n][i][j],ans);
}
int main()
{
	scanf("%d%d",&n,&m);
	init();
	DP();
	cout<<ans; 
	return 0;
}
