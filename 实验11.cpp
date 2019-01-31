#include<bits/stdc++.h>
using namespace std;
const int maxn = 2017;
int a[maxn][maxn];
int h[maxn],l[maxn],r[maxn];
int n,ans;
int main()
{
	scanf("%d",&n);
	for(int i=1; i<=n; i++)	   
	for(int j=1; j<=n; j++)
	    scanf("%d",&a[i][j]);
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)		   
			if(a[i][j]) h[j]=0;
			else h[j]++;
		for(int j=1; j<=n; j++)
		{
			l[j]=j;
			while(l[j]>1&&h[j]<=h[l[j]-1]) 
				l[j]=l[l[j]-1];
		}
		for(int j=n; j>=1; j--)
		{
			r[j]=j;
			while(r[j]<n&&h[j]<=h[r[j]+1]) 
				r[j]=r[r[j]+1];
		}
		for(int j=1; j<=n; j++)		   
			ans=max(h[j]*(r[j]-l[j]+1),ans);
	}
	cout<<ans;
	return 0;
}
