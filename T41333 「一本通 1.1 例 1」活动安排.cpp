#include<bits/stdc++.h>
using namespace std;
struct act
{
	int s;
	int t;
}a[1005];
bool cmp(act x,act y){return x.t<y.t;}
int main()
{
	int ans=1,n;
	cin>>n;
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i].s,&a[i].t);
	sort(a+1,a+1+n,cmp);
	int t=a[1].t;
	for(int i=2;i<=n;i++)
	{
		if(a[i].s>=t)
		{
			t=a[i].t;
			ans++;
		}
	}
	cout<<ans<<endl;
}
 
