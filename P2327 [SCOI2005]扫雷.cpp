#include<bits/stdc++.h>
using namespace std;
int n,ans=2,a[10001],b[10001];
void solve()
{
	for(int i=2;i<=n+1;i++)
	{
		b[i]=a[i-1]-b[i-1]-b[i-2];
		if(!(b[i]==1||b[i]==0))
		{
			ans--;
			break;
		}
		if(i==n+1&&b[i]!=0)
		{
			ans--;
			break;
		}
	}
}
int main()
{
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		cin>>a[i];
	b[1]=1,solve();
	b[1]=0,solve();
	cout<<ans<<endl;
	return 0;
}
