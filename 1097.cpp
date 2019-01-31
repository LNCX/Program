#include<iostream>
#include<cstring>
#define max 10005
using namespace std;
int a[max],b[max],c[max];
int lena,lenb,lenc=1,x;
char s1[max],s2[max];
char *mul(char *s1,char *s2)
{
	int a[max],b[max],c[max];
	int lena=0,lenb=0,lenc=1,x=0;
	char d[max];
	lena=strlen(s1),lenb=strlen(s2);
	for(int i=0;i<lena;i++) a[lena-i]=s1[i]-'0';
	for(int i=0;i<lenb;i++) b[lenb-i]=s2[i]-'0';
	for(int i=1;i<=lena;i++)
	{
		x=0;
		for(int j=1;j<=lenb;j++)
		{
			c[j+i-1]+=a[i]*b[j]+x;
			x=c[j+i-1]/10;
			c[j+i-1]%=10;
		}
		c[i+lenb]=x;
	}
	lenc=lena+lenb;
	c[lenc]=+x;
	while(c[lenc]==0&&lenc>1) lenc--;
	for(int i=lenc;i>0;i--)
		d[lenc-i]=c[i]+'0';
	return d;	
}
char *add(char *s1,char *s2)
{
	int a[max],b[max],c[max];
	int lena=0,lenb=0,lenc=1,x=0;
	char d[max];
	lena=strlen(s1),lenb=strlen(s2);
	for(int i=0;i<lena;i++) a[lena-i]=s1[i]-'0';
	for(int i=0;i<lenb;i++) b[lenb-i]=s2[i]-'0';
	while(lenc<=lena||lenc<=lenb)
	{
		c[lenc]=a[lenc]+b[lenc]+x;
		x=c[lenc]/10;
		c[lenc]%=10;
		lenc++;
	}
	c[lenc]=x;
	if(c[lenc]==0) lenc--;
	for(int i=lenc;i>0;i--)
		d[lenc-i]=c[i]+'0';
	return d;
}
int main()
{
	int n;
	cin>>n;
	char *f1,*f2,*f;
	char mul3[2]="3",mul2[2]="2";
	strlen(mul3);
	f1=new char[max],f2=new char[max];
	f1[0]='1',f2[0]='1';
	for(int i=1;i<=n;i++)
	{
		f=new char[max];
		f=add(mul(mul3,f2),mul(mul2,f1));
		f1=f2;
		f2=f;
		delete f;
	}
	for(int i=0;i<strlen(f2);i++)
	cout<<f[i];
}
