#include<bits/stdc++.h>
using namespace std;
string a[12];
map<string,int> cnt;
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		string s;
		int m,p;
		cin>>s>>m>>p;
		int k;
		if(p!=0) k=m/p;
		else k=0;
		cnt[s]-=k*p;
		for(int j=1; j<=p; j++)
		{
			string person;
			cin>>person;
			cnt[person]+=k;
		}
	}
	for(int i=1;i<=n;i++)
		cout<<a[i]<<" "<<cnt[a[i]]<<endl;
}
