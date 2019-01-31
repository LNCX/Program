#include<iostream>
#include<cstring>
#define max 205 
using namespace std;
int a[max],b[max],c[max];
int lena,lenb,lenc,x;
char s1[max],s2[max];
int main()
{
	cin>>s1>>s2;
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
	for(int i=lenc;i>0;i--) cout<<c[i];
}
