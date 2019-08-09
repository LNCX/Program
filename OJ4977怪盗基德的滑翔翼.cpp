#include<cstdio>
#include<iostream>
#define N 10005
using namespace std;
int main()
{
	int k;
	cin>>k;
	while(k--)
	{
		int n,a[N],b[N],c[N];
		cin>>n;
		for(int i=1;i<=n;i++) scanf("%d",&a[i]); 
		for(int i=1;i<=n;i++)
		{
			int max=0;
			for(int j=1;j<i;j++)
				if(a[j]<a[i]&&b[j]>max)
					max=b[j];
			b[i]=max+1;
		}
		for(int i=n;i>=1;i--)
		{
			int max=0;
			for(int j=n;j>i;j--)
				if(a[j]<a[i]&&c[j]>max)
					max=c[j];
			c[i]=max+1;
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(b[i]>ans) ans=b[i];
			if(c[i]>ans) ans=c[i];
		}
		cout<<ans<<endl;
	}
}
