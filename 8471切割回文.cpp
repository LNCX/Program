#include<cstring>
#include<iostream>
using namespace std;
int f[105]={0};
char a[1005];
bool search(int l,int r)
{
	for(int i=l;i<=(l+r)/2+1;i++)
		if(a[i]!=a[l+r-i]) 
			return false;
	return true;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>a;
		int len=strlen(a);
		for(int i=0;i<len;i++)
		for(int k=1;k<=i-1;k++)
		{
			f[i]=f[i-1]+1;
			if(search(k,i))
				f[i]=min(f[i],f[i-k]+1);
		}
		cout<<f[len-1]<<endl;
	}
}
