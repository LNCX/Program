#include<bits/stdc++.h>
using namespace std;
const int N=1505;
struct
{
	int num;
	int child[N];
}tree[N];
int f[N][2],a[N];
void dp(int x)
{
	f[x][1]=1;
	f[x][0]=0;
	if(tree[x].num==0) return;
	for(int i=1;i<=tree[x].num;i++)
	{
		dp(tree[x].child[i]);
		f[x][0]+=f[tree[x].child[i]][1];
		f[x][1]+=min(f[tree[x].child[i]][0],f[tree[x].child[i]][1]);
	}
}
int main()
{
	int n,root=1;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x,y;
		scanf("%d",&x);x++;
		scanf("%d",&tree[x].num);
		for(int j=1;j<=tree[x].num;j++)
		{
			scanf("%d",&y);y++;
			tree[x].child[j]=y;
			a[y]=1;
		}
	} 
	while(a[root]) root++;
	dp(root);
	printf("%d\n",min(f[root][0],f[root][1]));
	return 0;
}
