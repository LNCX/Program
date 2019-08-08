#include<bits/stdc++.h>
using namespace std;
const int N=205;
const int mod=2009;
int len;
struct mat
{
	int num[N][N];
};
mat operator*(mat a,mat b)
{
	mat ans;
	memset(ans.num,0,sizeof(ans));
	for(int i=1;i<=len;i++)
		for(int j=1;j<=len;j++)
			for(int k=1;k<=len;k++)
				ans.num[i][j]=(ans.num[i][j]+a.num[i][k]*b.num[k][j])%mod;
	return ans;
}	
mat a,b;
int main()
{
	int n,t;
	cin>>n>>t;
	len=10*(n+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			char c;
			scanf(" %c",&c);
			for(int k=1;k<c-'0';k++)
				a.num[i*10+k][i*10+k+1]=1;
			if(c-'0')
				a.num[i*10+c-'0'][j*10+1]=1;
		}
	for(int i=1;i<=len;i++)
		b.num[i][i]=1;
	while(t)
	{
		if(t&1) b=b*a;
		a=a*a;
		t>>=1;
	}
	printf("%d\n",b.num[11][n*10+1]);
	return 0;
}
