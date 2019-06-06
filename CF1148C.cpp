#include <bits/stdc++.h>
using namespace std;
const int maxn=333000;
int n,d[maxn],p[maxn];
vector< pair<int,int> >v;
void change(int x,int y)
{
	if(x==y)return;
	v.push_back(make_pair(x,y));
	p[d[x]]=y,p[d[y]]=x;
	swap(d[x],d[y]);
}
int main()
{
    cin>>n;
	for(int i=1;i<=n;i++)
		cin>>d[i],p[d[i]]=i;
	for(int i=1;i<=n;i++)
    {
		int e=n/2+i/2*(i%2?-1:1);
		int j=p[e];
		if(j<=n/2)
        {
			change(j,n);
			if(e>n/2)change(n,1),change(1,e);
			else change(n,e);
		}
		else
        {
			change(j,1);
			if(e-1<n/2)change(n,1),change(n,e);
			else change(1,e);
		}
	}
	printf("%lu\n",v.size());
	for(auto i:v)
		printf("%d %d\n",i.first,i.second);
}