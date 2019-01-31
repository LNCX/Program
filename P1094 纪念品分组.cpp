#include<bits/stdc++.h>
using namespace std;
int top,tail,ans,w,n,a[30005];
int main()
{
	cin>>w>>n;
	for(int i=1;i<=n;i++)	scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	top=1,tail=n;
	while(top<=tail)
	{
		if(a[top]+a[tail]<=w)	top++;
		tail--;
		ans++;
	}
	cout<<ans<<endl;
}
