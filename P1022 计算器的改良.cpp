#include<bits/stdc++.h>
using namespace std;
char n[10005],w;
float a,b,nag=1;
int num(int r)
{
	int l=r,sum=0;
	while(n[l]!='+'&&n[l]!='-'&&n[l]!='='&&l>=0)l--;
	for(int i=l+1;i<=r;i++)
	{
		sum*=10;
		sum+=n[i]-'0';
	}
	if(n[l]=='-') sum=-sum;
	return sum;
}
int word(int r)
{
	int l=r,sum=0;
	if(r==0||n[r-1]=='+'||n[r-1]=='=') return 1;
	else if(n[r-1]=='-') return -1;
	while(n[l]!='+'&&n[l]!='-'&&n[l]!='='&&l>=0)l--;
	for(int i=l+1;i<r;i++)
	{
		sum*=10;
		sum+=n[i]-'0';
	}
	if(n[l]=='-') sum=-sum;
	return sum;
}
int main()
{
	scanf("%s",n);
	n[strlen(n)]='+';
	int lenn=strlen(n)+1;	
	for(int i=0;i<strlen(n);i++)
	{
		if(n[i]=='+'||n[i]=='-'||n[i]=='=')
			if('0'<=n[i-1]&&n[i-1]<='9')		
				a+=num(i-1)*nag;
			else if('a'<=n[i-1]&&n[i-1]<='z')	
				{
					b+=word(i-1)*nag;
					w=n[i-1];
				}
		if(n[i]=='=')	nag=-1;
	}
	printf("%c=%.3f\n",w,-a/b); 
} 
