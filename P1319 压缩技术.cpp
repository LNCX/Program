#include<bits/stdc++.h>
using namespace std;
int ans[205][205],a[50000];
int main()
{
	int n,sum=0,len;
	cin>>n;
	for(int i=1;sum!=n*n;i++)
	{
		scanf("%d",&a[i]);
		sum+=a[i];
		len=i;
	}
	sum=0;
	for(int i=1;i<=len;i++)
	for(int j=1;j<=a[i];j++)
	{
		cout<<(i+1)%2;
		sum++;
		if(sum%n==0) cout<<endl;
	}
	return 0;
}

