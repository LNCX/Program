#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
struct mat
{
	long long d[5][5];
}e,a,b,c,ans,res;
mat mul(mat x,mat y)
{
	memset(res.d,0,sizeof(res.d));
	for(int i=1;i<=2;i++)
	for(int j=1;j<=2;j++)
	for(int k=1;k<=2;k++)
		res.d[i][j]=res.d[i][j]%mod+x.d[i][k]*y.d[k][j]%mod;
	return res;
}
int main()
{
	long long n;
	scanf("%lld",&n);
	n-=2;
	e.d[1][1]=e.d[2][2]=1;	
	c.d[1][1]=c.d[2][1]=1;
	a.d[1][1]=a.d[1][2]=a.d[2][1]=1;
	b=e;
	while(n)
	{
		if(n%2==1)
			b=mul(b,a);
		n/=2;
		a=mul(a,a); 
	}
	for(int i=1;i<=2;i++)
	for(int j=1;j<=1;j++)
	for(int k=1;k<=2;k++)
		ans.d[i][j]=ans.d[i][j]%mod+b.d[i][k]*c.d[k][j]%mod;
	cout<<ans.d[1][1]%mod<<endl;
}
