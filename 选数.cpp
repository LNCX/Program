#include<iostream>
using namespace std;
bool b[21];
int sum,n,k,ans,a[21];
bool deal(int x)
{
	if(x==0||x==1) return false;
	for(int i=2;i*i<=x;i++)
		if(x%i==0) return false;
	return true;
}
void search(int l,int m)
{
	if(m>k)
	{
		if(deal(sum)) ans++;
		return;
	}
	for(int i=l;i<=n;i++)
	if(!b[i])
	{
		sum+=a[i];
		b[i]=true;
		search(i+1,m+1);
		b[i]=false;
		sum-=a[i];
	}
}
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	search(1,1);
	cout<<ans<<endl;
}
