#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
int ans[maxn],s[maxn];
int a[maxn],b[maxn],m[maxn];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	for(int i=1;i<=n;i++)
	{
		m[i]=min(a[i],b[i]);
		s[i]=i;
	}
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
			if(m[i]>m[j])
			{
				swap(m[i],m[j]);
				swap(s[i],s[j]);
			}
	int k=0,t=n+1;
	for(int i=1;i<=n;i++)
		if(m[i]==a[s[i]])
		{
			k++;
			ans[k]=s[i];
		}
		else
		{
			t--;
			ans[t]=s[i];
		}
	k=0,t=0;
	for(int i=1;i<=n;i++)
	{
		k+=a[ans[i]];
		if(t<k) t=k;
		t+=b[ans[i]];
	}
	cout<<t<<endl;
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	return 0;
}
