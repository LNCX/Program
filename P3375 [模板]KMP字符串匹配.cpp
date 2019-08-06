#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
char a[N],b[N];
int n,m,k,p[N];
int main()
{
	scanf("%s%s",a+1,b+1);
	n=strlen(a+1),m=strlen(b+1);
	for(int i=1;i<m;i++)
	{
		while(k>0&&b[k+1]!=b[i+1]) k=p[k];
		if(b[i+1]==b[k+1]) k++;
		p[i+1]=k;
	}
	k=0;
	for(int i=0;i<n;i++)
	{
		while(k>0&&b[k+1]!=a[i+1]) k=p[k];
		if(b[k+1]==a[i+1]) k++;
		if(k==m)
		{
			printf("%d\n",i+1-m+1);
			k=p[k];
		}
	}
	for(int i=1;i<=m;i++)
		printf("%d ",p[i]);
	return 0;
}