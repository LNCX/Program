#include<bits/stdc++.h>
using namespace std;
char a[1000];
int n,b[10001];
int main()
{
	cin>>n;
	cin>>a;
	for(int i=n;i<n*2;i++)a[i]=a[i-n];
	int mx=0;
	for(int i=0;i<2*n;i++)
	{
		int l=i,r=i+1;
		char la=a[l];
		char ra=a[r];
		if(a[l]=='w')la=a[l-1];
		if(a[r]=='w')ra=a[r-1];
		int ans=0;
		while(l>=0)
		{
			if(a[l]==la||a[l]=='w')ans++;
			else break;
			l--;
		}
		while(r<2*n)
		{
			if(a[r]==ra||a[r]=='w')ans++;
			else break;
			r++;
		}
		mx=max(mx,ans);
	}
	if(mx>n) mx=n;
	cout<<mx<<endl;
}
