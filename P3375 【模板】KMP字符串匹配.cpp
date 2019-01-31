#include<bits/stdc++.h>
using namespace std;
#define maxn 1000005
int k,m,n,p[maxn];
char a[maxn],b[maxn];
int main()
{
	scanf("%s",a+1),m=strlen(a+1);
	scanf("%s",b+1),n=strlen(b+1);
	for(int i=1;i<n;i++)
	{
		while(k>0&&b[i+1]!=b[k+1]) 
			k=p[k];
		if(b[i+1]==b[k+1])
			k++;
		p[i+1]=k;
	}
	k=0;
	for(int i=0;i<m;i++)
	{
		while(k>0&&a[i+1]!=b[k+1])
			k=p[k];
		if(a[i+1]==b[k+1])
			k++;
		if(k==n)
		{
			printf("%d\n",i+1-n+1);
			k=p[k];
		}
	}
	for(int i=1;i<=n;i++)
		printf("%d ",p[i]);
}
