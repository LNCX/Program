#include<cstdio>
#include<iostream>
using namespace std;
int a[100005][4];
int main()
{
	int n=1;
	while(scanf("%d",&a[n][1]))
	{
		a[n][2]=1;
		a[n][3]=0;
		n++;
	}
	n--;
	a[n][2]=1,a[n][3]=0;
	for(int i=n-1;i>=1;i--)
	{
		int l=0,k=0;
		for(int j=i+1;j<=n;j++)
		{
			if(a[i][1]<a[j][1]&&(a[j][2]>l))
			{
				l=a[j][2];
				k=j;
			}
		}
		if(l>0)
		{
			a[i][2]=l+1;
			a[i][3]=k;
		}
	}
	int max=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i][2]>max)
			max=a[i][2];
	}
	cout<<max<<endl;
}
