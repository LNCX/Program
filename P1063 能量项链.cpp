#include<bits/stdc++.h>
using namespace std;
int ans,n,h[305],t[305],f[305][305];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>h[i];
		h[i+n]=h[i];
		t[i+n-1]=h[i+n];
		t[i-1]=h[i];
	}
	for(int l=1;l<=n;l++)
	for(int i=1;i<=2*n-l+1;i++)
	{
		int j=i+l-1;
		for(int k=i;k<=j-1;k++)
			f[i][j]=max(f[i][j],f[i][k]+f[k+1][j]+h[i]*t[k]*t[j]);
	}
	for(int i=1;i<=n;i++)
		ans=max(ans,f[i][i+n-1]);
	cout<<ans<<endl;
}

