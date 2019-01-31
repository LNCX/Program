#include<bits/stdc++.h>
using namespace std;
int main()
{
	int f[10005]={1},a[105],n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	for(int v=m;v>=a[i];v--)
		f[v]+=f[v-a[i]];
	cout<<f[m]<<endl;
}
