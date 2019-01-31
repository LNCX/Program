#include<bits/stdc++.h>
using namespace std;
const int mod=9999973;
long long f[108][108][108];//f[i][j][k]表示放了前i行 
//有j列是有1个棋子，有k列有两个棋子的合法方案总数 
long long ans=0;
int C(int x)
{
	return ((x*(x-1))/2)%mod;	
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	f[0][0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=m;j++)
			for(int k=0;k<=m-j;k++)
			{	
				//no 
				f[i][j][k]+=f[i-1][j][k];
				//one
				//put on no-chess
				if(j>=1) f[i][j][k]+=f[i-1][j-1][k]*(m-j+1-k);
				//put on j of one-chess
				if(k>=1) f[i][j][k]+=f[i-1][j+1][k-1]*(j+1);
				//two
				//put on no-chess and one-chess
				if(k>=1) f[i][j][k]+=f[i-1][j][k-1]*j*(m-j-(k-1));
				//put on both no-chess
				if(j>=2) f[i][j][k]+=f[i-1][j-2][k]*C(m-(j-2)-k);
				//put on both one-chess
				if(k>=2) f[i][j][k]+=f[i-1][j+2][k-2]*C(j+2);
				f[i][j][k]%=mod;
			}
	for(int i=0;i<=m;i++)
		for(int j=0;j<=m;j++)
		(ans+=f[n][i][j])%=mod;
	printf("%lld\n",ans);
	return 0;
}
