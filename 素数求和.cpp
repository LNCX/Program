#include<iostream>
using  namespace std;
int main()
{
	int m;
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		int n;
		scanf("%d",&n);
		int a[n]={0};
		int sum=0;
		for(int j=0;j<n;j++)
		{
			cin>>a[n];
			if(a[n]==1)
				sum+=0;
			else if(a[n]==2)
				sum+=2;
			else
			{	
				int flag=1;
				for(int k=2;k<a[n];k++)
				{
					if(a[n]%k==0)
						flag=0;
				}
				if(flag==1)
				 sum+=a[n];
			}
		}
		cout<<sum;
		sum=0;
	}
} 
