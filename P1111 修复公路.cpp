#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
const int maxm=2e5+5;
struct node
{
    int u,v,w;
    bool operator <(const node &x) const
    {
        return this->w<x.w;
    }
}a[maxm];
int n,m,f[maxn],size[maxn];
int find(int x)
{
	if(x==f[x]) return f[x];
	return f[x]=find(f[x]);
}
void add(int x,int y)
{
	x=find(x),y=find(y);
	f[x]=y;
	n--;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
        scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
    sort(a+1,a+1+m);
	for(int i=1;i<=n;i++)
		f[i]=i;
	for(int i=1;i<=m;i++)
	{
		if(f[a[i].u]!=f[a[i].v]) 
			add(a[i].u,a[i].v);
		if(n==1)
		{
			cout<<a[i].w<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
	return 0;
}
