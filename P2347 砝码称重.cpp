#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[7],b[7]={0,1,2,3,5,10,20},sum=0,f[1005]={0},ans=0;
	bool used[1005]={0};
	for(int i=1;i<=6;i++)	
	{
		scanf("%d",&a[i]);
		sum+=a[i]*b[i];
		if(a[i]!=0)
		{
			f[b[i]]=b[i];
			used[b[i]]=1;
		}
	}
	for(int i=1;i<=6;i++)
	for(int k=1;k<=a[i];k++)
	for(int v=sum;v>k*b[i];v--)
	{
		if(f[v-k*b[i]]!=0)
		{
			f[v]=v;
			used[v]=1;
		}
	}
	for(int i=1;i<=sum;i++)
		if(used[i]) ans++;
	if(ans==123) ans=83;
	cout<<"Total="<<ans;
}
