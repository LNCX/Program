#include<iostream>
#define maxn 10005
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[maxn]={1};
	int len=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=len;j++)
		{
			int x=a[j]*i/10;
			a[j]=a[j]*i%10;
			a[j]+=x;
			if(x!=0) len++;
		}
	}
	for(int i=len-1;i>=0;i--) cout<<a[i];
}
