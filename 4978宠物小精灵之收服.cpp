#include <bits/stdc++.h>
using namespace std;
int b[3000][3000];
int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	int a,z,r=0,c=0;
	for(int h=1;h<=k;h++)
	{
		cin>>a>>z;
		for(int i=n;i>=a;i--)
		for(int j=m;j>=z;j--)
		{
			b[i][j]=max(b[i][j],b[i-a][j-z]+1);
			if(b[i][j]>c)
			c=b[i][j],r=m-j;
			else if(b[i][j]==c&&m-j>r)
			r=m-j;
		}
	}
	if(c==0) r=m;
	printf("%d %d\n",c,r);
	return 0;
}
