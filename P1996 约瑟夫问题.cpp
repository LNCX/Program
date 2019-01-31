#include<bits/stdc++.h>
using namespace std;
int main()
{
	int step,count=0,n,m,a[105]={0};
	cin>>n>>m;
	step=n;
	for(int i=1;i<=n;i++)
		a[i]=i%n+1;
	while(count<n)
	{
		count++;
		int k=1;
		while(k<m)
		{
			step=a[step];
			k++;
		}
		printf("%d ",a[step]);
		a[step]=a[a[step]];
	}
}

