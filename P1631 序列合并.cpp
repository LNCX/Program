#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
int n,a[maxn],b[maxn],loc[maxn];
priority_queue<pair<int,int> >q;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) scanf("%d",&b[i]);
	for(int i=1;i<=n;i++)
	{
		q.push(make_pair(-a[i]-b[1],i));
		loc[i]=1;
	}
	while(n--)
	{
		printf("%d ",-q.top().first);
		int x=q.top().second;q.pop();
		q.push(make_pair(-a[x]-b[++loc[x]],x));
	}
}
