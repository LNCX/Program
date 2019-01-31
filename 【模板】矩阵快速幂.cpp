#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int len,k,a[105][105],ans[105][105];
void mul(int *n)
{
	//*(*(a+i)+j)
	long long res[105][105]={0};
	for(int i=1;i<=len;i++)
	for(int j=1;j<=len;j++)
	for(int k=1;k<=len;k++)
		res[i][j]+=(*(n+i*len+k))*a[k][j];
	for(int i=1;i<=len;i++)
	for(int j=1;j<=len;j++)
		*(n+i*len+j)=res[i][j]%mod;
}
int main()
{
	scanf("%d%d",&len,&k);
	for(int i=1;i<=len;i++)
	for(int j=1;j<=len;j++)
		scanf("%d",&a[i][j]);
	for(int i=1;i<=len;i++)
		ans[i][i]=1;
	while(k)
	{
		if(k%2==1)
		//n=ans,m=a;
		mul(ans[0]);
		k>>=1;
		//n=a,m=a;
		mul(a[0]);
	}
	for(int i=1;i<=len;i++)
	{
		for(int j=1;j<=len;j++)
			printf("%d ",ans[i][j]%mod);
		printf("\n");
	}
}
