#include<iostream>
using namespace std;
bool a[10005];
int ans,l,m;
int main()
{	
	cin>>l>>m;
	for(int i=1;i<=m;i++)
	{
		int left,right;
		cin>>left>>right;
		for(int j=left;j<=right;j++) a[j]=true;
	}
	for(int i=0;i<=l;i++) if(a[i]==false) ans++;
	cout<<ans<<endl; 
}
