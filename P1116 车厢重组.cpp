#include<bits/stdc++.h>
using namespace std;
int a[10005];
int main()
{
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<i;j++)
			if(a[j]>a[i]) 
			{
				swap(a[i],a[j]);
				ans++;
			}
	cout<<ans<<endl;
	return 0;
}
