#include<bits/stdc++.h>
using namespace std;
struct car
{
	string s;
	int v,w;
	string name;
}a[102];
int n,q;
int main()
{
	cin>>n;
	for(int i=0,t;i<n;i++)
		cin>>a[i].s>>a[i].v>>a[i].w>>t>>a[i].name;
	cin>>q;
	for(int op,t=0;t<q;t++)
	{
		cin>>op;
		int id=0,m=0;
		double k;
		string h;
		switch (op)
		{
			case 1:
			{
				cin>>id;
				cout<<a[id-1].s<<endl;
				break;
			}
			case 2:
			{
				cin>>h;
				for(int i=0;i<n;i++)
					if(h==a[i].s)
					{
						cout<<a[i].name<<endl;
						break;
					}
				break;
			}
			case 3:
			{
				cin>>k;
				for(int i=0;i<n;i++)
					if(a[i].v*1.0/a[i].w>=k)m++;
				cout<<m<<endl;
				break;
			}
		}
	}
	return 0;
}


