#include<bits/stdc++.h>
using namespace std;
int n,q;
struct text
{
	int num;
	char name;
}x[102];
int main()
{
	cin>>n>>q;
	for(int i=0;i<n;i++)
		cin>>x[i].num;
	string t;
	for(int i=0;i<n;i++)
	{
		cin>>t;
		x[i].name=t[0];
	}
	for(int i=0;i<q;i++)
	{
		cin>>t;
		int l,r,s=0;
		cin>>l>>r;
		for(int j=l-1;j<r;j++)
			if(x[j].name==t[0])
				s+=x[j].num;
		cout<<s<<endl;
	}
	return 0;
}


