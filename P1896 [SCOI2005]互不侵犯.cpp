#include<bits/stdc++.h>
using namespace std;
long long ans=0,f[11][512][512];//f[i][j][s]表示放到第i行，放了k个king，状态为j 
int num[512],s[512],N,K,sum;
int main()
{
	int N,K;
	scanf("%d%d",&N,&K);
	for(int i=0;i<(1<<N);i++)
	{
		if(i&(i<<1)) 
			continue;
		int k=0;
		for(int j=0;j<N;j++) 
			if(i&(i<<j))
				k++;
		s[++sum]=i;
		num[sum]=k;
	}
	f[0][1][0]=1;
	for(int i=1;i<=N;i++)
	for(int j=1;j<=sum;j++)
	for(int k=0;k<=K;k++)
		if(k>=num[j])
			for(int t=1;t<=sum;t++)
				if(!(s[t]&s[j])&&!(s[t]&(s[j]<<1))&&!(s[t]&(s[j]>>1)))
					f[i][j][k]+=f[i-1][t][k-num[j]];
	for(int i=1;i<=sum;i++)
		ans+=f[N][i][K];
	cout<<ans<<endl;
	return 0;
}
