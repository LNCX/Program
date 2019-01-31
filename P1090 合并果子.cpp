#include<bits/stdc++.h>
using namespace std;
int temp,n,a[500005],top,tail;
long long ans;
void swap(int &x,int &y)
{
	int temp=x;
	x=y;
	y=temp;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)	scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	top=1,tail=n;
	if(top==tail)
	{
		cout<<a[top]<<endl;
		return 0;
	}
	while(top<tail)
	{
		int temp=a[top]+a[top+1];
		ans+=temp;
		top+=2;
		tail++;
		a[tail]=temp;
		for(int i=tail-1;i>=top;i--)
			if(a[i]>a[tail])
				swap(a[i],a[tail]);
			else break;
	}
	cout<<ans<<endl;
}
