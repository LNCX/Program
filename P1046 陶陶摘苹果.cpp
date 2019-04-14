#include<iostream>
using namespace std;
int main()
{
	int n,a[10],ans=0;
	for(int i=0;i<10;i++)
		cin>>a[i];
	cin>>n;
	for(int i=0;i<10;i++)
		if(n+30>=a[i]) ans++;
	cout<<ans<<endl;
}
