#include<bits/stdc++.h>
using namespace std;
const int maxn=305;
int n,m,s[maxn],f[maxn][maxn];
vector<int>son[maxn];
void dp(int x)
{
	for(int i=0;i<son[x].size();i++)
	{
		int y=son[x][i];
		dp(y);
		for(int t=m;t>=0;t--)
			for(int j=t;j>=0;j--)
				f[x][t]=max(f[x][t],f[x][t-j]+f[y][j]);
	}
	if(x!=0)
		for(int t=m;t>0;t--)
			f[x][t]=f[x][t-1]+s[x];
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int k;
		scanf("%d%d",&k,&s[i]);
		son[k].push_back(i);
	}
	dp(0);
	cout<<f[0][m]<<endl;
	return 0;
}
