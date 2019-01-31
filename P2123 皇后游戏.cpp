#include<bits/stdc++.h>
using namespace std;
struct node
{
	int a,b;
	long long c;
}p[20005];
bool cmp(node x,node y)
{
	return min(x.a,y.b)<min(x.b,y.a);
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		long long s=0;
		for(int i=1;i<=n;i++)
			scanf("%d%d",&p[i].a,&p[i].b);
		sort(p+1,p+1+n,cmp);
		for(int i=1;i<=n;i++)
		{
			s+=p[i].a;
			p[i].c=max(s,p[i-1].c)+p[i].b;
		}
		cout<<p[n].c<<endl;
	}
}
