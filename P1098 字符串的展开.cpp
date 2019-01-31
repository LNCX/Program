#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int p1,p2,p3,lena;
char a[1005];
void f(int l,int r)
{
	int count=0,flag=0;
	char b[1005]={0};
	if(a[l]>=a[r]||abs(a[l]-a[r])>=40)	printf("-");
	if('a'<=a[l]&&a[l]<='z'&&a[r]-a[l]<='z'-'a'&&p1==2)
		flag=1;
	if(a[l]<a[r]&&('a'<=a[l]&&a[r]<='z')||('0'<=a[l]&&a[r]<='9'))
	for(int i=a[l]+1;i<=a[r]-1;i++)
	for(int j=1;j<=p2;j++)
	{
		if(p1==3) b[count]='*';
		else b[count]=i+flag*('A'-'a');
		count++; 
	}
	if(p3==2)
		for(int i=count-1;i>=0;i--)
			cout<<b[i];
	else
		for(int i=0;i<count;i++) 
			cout<<b[i];
}
int main()
{
	scanf("%d%d%d%s",&p1,&p2,&p3,a);
	lena=strlen(a);
	int l=0,r=0;
	for(int i=0;i<lena;i++)
	{
		if(a[i]!='-'||(a[i]=='-'&&(a[i-1]=='-'||a[i+1]=='-'))) printf("%c",a[i]);
		else f(i-1,i+1);
	}
}
