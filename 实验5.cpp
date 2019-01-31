#include <bits/stdc++.h>
using namespace std;

char a[505],b[505],i,la,lb;

int max(int a,int b)
{
	if (a>b)return a;
	else return b;
}

int main()
{
	i=1;
	a[1]=getchar();
	while(a[i]<='9'&&a[i]>='0')
	{
		i++;
		a[i]=getchar();
	}
	i=1;
	b[1]=getchar();
	while(b[i]<='9'&&b[i]>='0')
	{
		i++;
		b[i]=getchar();
	}
	for(i=0; i<505; i++)
	{
		if(a[i]=='\0'||b[i]=='\0')b[i]=a[i]+b[i];
		else b[i]=a[i]+b[i]-'0';
	}
	for(i=504; i>0; i--)
	{
		if(b[i]>'9')
		{
			b[i]-=10;
			b[i-1]+=1;
		}
	}
	if(b[0]==1)b[0]+='0';
	i=0;
	while(b[i]<='9'&&b[i]>='0')
	{
		cout<<b[i];
		i++;
	}
}
