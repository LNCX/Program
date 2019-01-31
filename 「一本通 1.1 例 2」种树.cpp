#include<bits/stdc++.h>
using namespace std;
struct node
{
	int b;
	int e;
	int t;
}a[5005];
int n,h,ans=0;
bool used[30005];
bool cmp(node x,node y){return x.e<y.e;}
int main()
{
	
	cin>>n>>h;
	for(int i=1;i<=h;i++)
		scanf("%d%d%d",&a[i].b,&a[i].e,&a[i].t);
	sort(a+1,a+1+h,cmp);
	for(int i=1;i<=h;i++)
	{
		int s=0;
		for(int j=a[i].b;j<=a[i].e;j++)
			if(used[j]) s++;
		if(s>=a[i].t) continue;
		for(int j=a[i].e;j>=a[i].b;j--)
		{
			used[j]=true;
			s++;
			ans++;
			if(s==a[i].t) break;
		}
	}
	cout<<ans<<endl;
}
