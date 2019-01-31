#include<bits/stdc++.h>
using namespace std;
string x;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		cin>>x;
		int s1=0,s2=0,s=0;
		string x1,x2,x3;
		if(m==1)
		{
			int s1=0;
			s2=0;
			for(int i=0;i<n;++i)
			{
				if(i%2==0)
				{
					if(x[i]=='1')
						s1++;
					else
						s2++;
				}
				else
				{
					if(x[i]=='1')
						s2++;
					else
						s1++;
				}
			}
			if(s1<s2)
			{
				cout<<s1<<endl;
				for(int i=0; i<n; ++i)
				{
					if(i%2==0)
						cout<<0;
					else
						cout<<1;
				}
			}
			else
			{
				cout<<s2<<endl;
				for(int i=0; i<n; ++i)
				{
					if(i%2==0)
						cout<<1;
					else
						cout<<0;
				}
			}
			cout<<endl;
		}
		else
		{
			x1=x;
			x2=x;
			int i,a=0,b=0;
			for(i=0; i<n; ++i)
			{
				if(x[i]=='1')
				{
					a++;
					b=0;
				}
				else
				{
					b++;
					a=0;
				}
				if(a>m)
				{
					int p=i;
					if(i<n-1&&x[i+1]=='0')
					{
						p--;
						b=0;
						a=1;
					}
					else
					{
						b=1;
						a=0;
					}
					x1[p]=(x[p]=='1'?'0':'1');
					s++;
				}
				else if(b>m)
				{
					int p=i;
					if(i<n-1&&x[i+1]=='1')
					{
						p--;
						b=1;
						a=0;
					}
					else
					{
						b=0;
						a=1;
					}
					x1[p]=(x[p]=='1'?'0':'1');
					s++;
				}
			}
			cout<<s<<endl<<x1<<endl;
		}
	}
	return 0;
}

