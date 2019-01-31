#include<iostream>
using namespace std;
int n,m,ans=0,count=0;
int dfs(int i)
{
	if(i==1&&count==m)
	{
		ans++;
		return 0;
	}
	if(count>m) return 0;
	count++;
	dfs((i+1)%n);
	if(i==1) dfs(n);
	else dfs(i-1);
	count--;
}
int main()
{
	cin>>n>>m;
	dfs(1);
	cout<<ans<<endl;
}
