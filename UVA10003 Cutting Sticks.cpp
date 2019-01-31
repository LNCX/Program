#include<bits/stdc++.h>
using namespace std;
int l,n,a[1005],f[105][105];
int main()
{
	while(cin>>l)
	{
		if(!l)return 0;
		cin>>n;
		memset(f,10,sizeof(f));
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			f[i][i+1]=0;
		}
		a[n+1]=l;f[0][1]=0;
		for(int c=2;c<=n+1;c++)
		{
			for(int i=0;i+c<=n+1;i++)
			{
				int j=i+c;
				int minx=1e9;
				for(int k=i+1;k<j;k++)
					minx=min(minx,f[i][k]+f[k][j]);
				f[i][j]=minx+a[j]-a[i];
			}
		}
		cout<<"The minimum cutting is "<<f[0][n+1]<<"."<<endl;
	}
}
