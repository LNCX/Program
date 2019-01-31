#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
bool used[maxn];
int n,a[maxn],w[maxn],clr[maxn];
void dfs(int x,int len)
{
	if(used[x]) return;
	if(a[x]==x||w[a[x]]) return;
	used[x]=true,clr[x]=len;
	if(clr[a[x]])
	{
		len=clr[x]-clr[a[x]]+1;
		for(int i=x;w[i]==0;i=a[i])
			w[i]=len;
		return;
	}
	dfs(a[x],len+1);
	clr[x]=0;
}
int search(int x)
{
	if(w[x]) return w[x];
	if(a[x]==x) return 1; 
	w[x]=search(a[x])+1;
	return w[x];
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) dfs(i,1);
	for(int i=1;i<=n;i++) w[i]=search(i);
	for(int i=1;i<=n;i++) printf("%d\n",w[i]);
	return 0;
}
