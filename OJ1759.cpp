#include<cstdio>
#include<iostream>
#define maxn 2005
using namespace std;
int main()
{
	int n,a[maxn],f[maxn];
	cin>>n;
	for(int i=1;i<=n;i++)	scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			if(a[i]>a[j]&&f[j]+1>f[i])
				f[i]=f[j]+1;
			else f[i]=f[j];
	cout<<f[n]<<endl;
	return 0;
}

