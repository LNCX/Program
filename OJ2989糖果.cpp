#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	int n,k;
	cin>>n>>k;
	int a[105]={0},sum=0,f[105]={0};
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	for(int i=1;i<=n;i++)
	for(int x=1;x*k<=sum;x++)
	for(int j=x*k;j>=a[i];j--)
		f[j]=max(f[j-a[i]]+a[i],f[j]);
	int ans=0;
	for(int x=1;x*k<=sum;x++)
		if(f[x*k]>ans)
			ans=f[x*k];
	cout<<ans<<endl;
}

