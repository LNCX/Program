#include<bits/stdc++.h>
using namespace std;
int len,used[10];
char a[10],b[10];
void f(int l,int r)
{
	for(int j=len-1;j>=0;j--)
	for(int i=l;i<=r;i++)
	{
		if(a[i]==b[j])
		{
			cout<<a[i];
			if(l<i) f(l,i-1);
			if(i<r) f(i+1,r);
			return;
		}
	}
}
int main()
{
	cin>>a>>b;
	len=strlen(a);
	f(0,len-1);
}

