#include<bits/stdc++.h>
using namespace std;
int n,a[50],l,r,x,y,sum;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	cin>>l>>r;
	for(int i=1;i<=n;i++)
	{
		if(a[i]<l) x+=l-a[i];
		if(a[i]>r) y+=a[i]-r;
		sum+=a[i];
	}
	if(sum>n*r) {cout<<-1<<endl;}
	else cout<<max(x,y)<<endl;
}
